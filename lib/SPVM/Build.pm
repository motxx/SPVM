package SPVM::Build;

use strict;
use warnings;

use Config;
use Carp 'confess';

use SPVM::Build::SPVMInfo;
use SPVM::Build::ExtUtil;
use SPVM::Build::JIT;
use SPVM::Build::Inline;

use File::Path 'rmtree';
use File::Spec;

sub new {
  my $class = shift;
  
  my $self = {};
  
  $self->{extutil} = SPVM::Build::ExtUtil->new;
  
  $self->{jit} = SPVM::Build::JIT->new;
  
  return bless $self, $class;
}

sub cleanup_build_dir {
  my $build_dir = $SPVM::BUILD_DIR;
  
  if (defined $build_dir && -d $build_dir) {
    opendir(my $build_dh, $build_dir);
    if ($build_dh) {
      while (my $build_process_dir_base = readdir $build_dh) {
        if ($build_process_dir_base =~ /^([0-9]+?)\.([0-9]+)?$/) {
          my $process_id = $1;
          my $process_start_time = $2;
          
          # Remove only old directory than self-process
          if ($process_start_time < $SPVM::PROCESS_START_TIME) {
            my $alive = kill 0, $process_id;
            
            # Only remove finished process's directory
            unless ($alive) {
              my $build_process_dir = "$build_dir/$build_process_dir_base";
              my @source_files =  glob "$build_process_dir/*";
              for my $source_file (@source_files) {
                # Never throw exception even if file is not removed.
                unlink $source_file;
              }
              # Never throw exception even if directory is not removed.
              rmdir $build_process_dir;
            }
          }
        }
      }
    }
  }
}

sub create_build_process_dir {
  my $build_dir = $SPVM::BUILD_DIR;
  
  unless (defined $build_dir) {
    confess "Can't create build process directory because build directory is not specified";
  }
  
  unless (-d $build_dir) {
    confess "Can't create build process directory because build directory $build_dir don't eixsts";
  }
  
  my $build_process_dir = File::Spec->catfile($build_dir, "$$.$SPVM::PROCESS_START_TIME");
  
  # Don't error check
  mkdir $build_process_dir;
  my $mkdir_error = $!;
  
  if (!-d $build_process_dir) {
    my $message = "Can't create build process directory $build_process_dir because mkdir fail";
    if ($mkdir_error) {
      $message .= " : $!";
    }
    confess $message;
  }
  
  return $build_process_dir;
}

sub extutil {
  my $self = shift;
  
  return $self->{extutil};
}

sub jit {
  my $self = shift;
  
  return $self->{jit};
}

sub compile_spvm {
  my $self = shift;
  
  # Compile SPVM source code
  my $compile_success = $self->compile();
  
  if ($compile_success) {
    # Build opcode
    $self->build_opcode;
    
    # Build run-time
    $self->build_runtime;
    
    # Bind native subroutines
    $self->bind_native_subs;
    
    # Build SPVM subroutines
    $self->build_spvm_subs;
  }
  
  return $compile_success;
}

my $package_name_h = {};

sub build_spvm_subs {
  my $self = shift;
  
  my $sub_names = SPVM::Build::SPVMInfo::get_sub_names();
  
  for my $abs_name (@$sub_names) {
    # Define SPVM subroutine
    no strict 'refs';
    
    # Declare package
    my ($package_name, $sub_name) = $abs_name =~ /^(?:(.+)::)(.+)/;
    $package_name = "SPVM::$package_name";
    unless ($package_name_h->{$package_name}) {
      
      my $code = "package $package_name; our \@ISA = ('SPVM::Perl::Object::Package');";
      eval $code;
      
      if (my $error = $@) {
        confess $error;
      }
      $package_name_h->{$package_name} = 1;
    }
    
    # Declare subroutine
    *{"SPVM::$abs_name"} = sub {
      
      my $return_value;
      eval { $return_value = SPVM::call_sub("$abs_name", @_) };
      my $error = $@;
      if ($error) {
        confess $error;
      }
      $return_value;
    };
  }
}

sub get_shared_lib_file {
  my ($self, $module_name) = @_;
  
  my $module_name2 = $module_name;
  $module_name2 =~ s/SPVM:://;
  my @module_name_parts = split(/::/, $module_name2);
  my $module_load_path = SPVM::Build::SPVMInfo::get_package_load_path($module_name2);
  
  my $shared_lib_path = $self->extutil->convert_module_path_to_shared_lib_path($module_load_path);
  
  return $shared_lib_path;
}

sub bind_native_subs {
  my $self = shift;
  
  my $native_func_names = SPVM::Build::SPVMInfo::get_native_sub_names();
  for my $native_func_name (@$native_func_names) {
    my $native_func_name_spvm = "SPVM::$native_func_name";
    my $native_address = $self->get_sub_native_address($native_func_name_spvm);
    unless ($native_address) {
      my $native_func_name_c = $native_func_name_spvm;
      $native_func_name_c =~ s/:/_/g;
      confess "Can't find native address of $native_func_name_spvm(). Native function name must be $native_func_name_c";
    }
    $self->bind_native_sub($native_func_name, $native_address);
  }
}

my $compiled_inline_shared_lib_file_h = {};

sub get_sub_native_address {
  my ($self, $sub_abs_name) = @_;
  
  my $package_name;
  my $sub_name;
  if ($sub_abs_name =~ /^(?:(.+)::)(.+)$/) {
    $package_name = $1;
    $sub_name = $2;
  }
  
  my $dll_package_name = $package_name;
  my $shared_lib_file = $self->get_shared_lib_file($dll_package_name);
  
  my $shared_lib_func_name = $sub_abs_name;
  $shared_lib_func_name =~ s/:/_/g;
  my $native_address = $self->extutil->search_shared_lib_func_address($shared_lib_file, $shared_lib_func_name);
  
  # Try inline compile
  unless ($native_address) {
    my $module_name = $package_name;
    $module_name =~ s/^SPVM:://;
    
    unless ($compiled_inline_shared_lib_file_h->{$module_name}) {
      my $module_dir = SPVM::Build::SPVMInfo::get_package_load_path($module_name);
      $module_dir =~ s/\.spvm$//;
      
      my $module_name_slash = $package_name;
      $module_name_slash =~ s/::/\//g;
      
      $module_dir =~ s/$module_name_slash$//;
      $module_dir =~ s/\/$//;
      
      # Build inline code
      my $build_dir = $SPVM::BUILD_DIR;
      unless (defined $build_dir && -d $build_dir) {
        confess "SPVM build directory must be specified for inline compile";
      }
      
      # Create build process directory
      my $build_process_dir = $SPVM::BUILD->create_build_process_dir;
      
      my $inline_shared_lib_file = $self->extutil->build_shared_lib(
        module_dir => $module_dir,
        module_name => "SPVM::$module_name",
        build_dir => $build_process_dir,
        inline => 1,
        quiet => 1,
      );
      
      $compiled_inline_shared_lib_file_h->{$module_name} = $inline_shared_lib_file;
    }
    
    $native_address = $self->extutil->search_shared_lib_func_address($compiled_inline_shared_lib_file_h->{$module_name}, $shared_lib_func_name);
  }
  
  return $native_address;
}

1;
