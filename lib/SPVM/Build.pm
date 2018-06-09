package SPVM::Build;

use strict;
use warnings;

use Config;
use Carp 'confess';

use SPVM::Build::SPVMInfo;
use SPVM::Build::Native;
use SPVM::Build::Precompile;
use SPVM::Build::Util;

use File::Path 'rmtree';
use File::Spec;

use SPVM();

sub new {
  my $class = shift;
  
  my $self = {@_};
  
  my $build_dir = $self->{build_dir};
  
  $self->{package_infos} ||= [];
  
  bless $self, $class;
  
  $self->{compiler} ||= $self->create_compiler;
  
  $self->{native} ||= SPVM::Build::Native->new(
    build_dir => $build_dir,
    compiler => $self->{compiler}
  );
  
  $self->{precompile} ||= SPVM::Build::Precompile->new(
    build_dir => $build_dir,
    compiler => $self->{compiler}
  );
  
  return $self;
}

sub use {
  my ($self, $package_name) = @_;
  
  my (undef, $file_name, $line) = caller;
  
  my $package_info = {
    name => $package_name,
    file => $file_name,
    line => $line,
  };
  
  return $package_info;
}

sub native {
  my $self = shift;
  
  return $self->{native};
}

sub precompile {
  my $self = shift;
  
  return $self->{precompile};
}

sub build_spvm {
  my $self = shift;
  
  # Compile SPVM source code
  my $compile_success = $self->compile_spvm();
  
  if ($compile_success) {
    # Build opcode
    $self->build_opcode;
    
    # Build run-time
    $self->build_runtime;
    
    # Build Precompile packages - Compile C source codes and link them to SPVM precompile subroutine
    $self->precompile->build;
    
    # Build native packages - Compile C source codes and link them to SPVM native subroutine
    $self->native->build;
    
    # Build SPVM subroutines
    $self->build_spvm_subs;
  }
  
  return $compile_success;
}

my $package_name_h = {};

sub build_spvm_subs {
  my $self = shift;
  
  my $sub_names = SPVM::Build::SPVMInfo::get_sub_names($self->{compiler});
  
  for my $abs_name (@$sub_names) {
    # Define SPVM subroutine
    no strict 'refs';
    
    # Declare package
    my ($package_name, $sub_name) = $abs_name =~ /^(?:(.+)::)(.+)/;
    $package_name = "$package_name";
    unless ($package_name_h->{$package_name}) {
      
      my $code = "package $package_name; our \@ISA = ('SPVM::Data');";
      eval $code;
      
      if (my $error = $@) {
        confess $error;
      }
      $package_name_h->{$package_name} = 1;
    }
    
    # Declare subroutine
    *{"$abs_name"} = sub {
      
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

1;
