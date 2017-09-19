package SPVM;

use 5.008007;
use strict;
use warnings;

use Config;

use SPVM::BaseObject;
use SPVM::Object;
use SPVM::Array;
use SPVM::Array::Byte;
use SPVM::Array::Short;
use SPVM::Array::Int;
use SPVM::Array::Long;
use SPVM::Array::Float;
use SPVM::Array::Double;
use SPVM::Array::Object;
use File::Temp 'tempdir';
use ExtUtils::CBuilder;
use Config;
use DynaLoader;
use SPVM::Build;
use File::Basename 'basename';


use Encode 'encode';

use Carp 'confess';

our $VERSION = '0.0267';

our $COMPILER;
our @PACKAGE_INFOS;
our %PACKAGE_INFO_SYMTABLE;
our $API;
our @INLINE_DLL_FILES;

our @PACKAGE_INFOS_INLINE;

sub import {
  my ($class, $package_name) = @_;
  
  # Add package infomations
  if (defined $package_name) {
    unless ($SPVM::PACKAGE_INFO_SYMTABLE{$package_name}) {
      my ($file, $line) = (caller)[1, 2];

      my $package_info = {
        name => $package_name,
        file => $file,
        line => $line
      };
      push @SPVM::PACKAGE_INFOS, $package_info;
      
      $SPVM::PACKAGE_INFO_SYMTABLE{$package_name} = 1;
      
      return $package_info;
    }
  }
  
  return;
}

sub _get_dll_file {
  my $package_name = shift;
  
  # DLL file name
  my $dll_base_name = $package_name;
  $dll_base_name =~ s/^.*:://;
  my $shared_lib_file_tail = 'auto/' . $package_name . '.native' . '/' . $dll_base_name;
  $shared_lib_file_tail =~ s/::/\//g;
  my $shared_lib_file;
  for my $dl_shared_object (@DynaLoader::dl_shared_objects) {
    my $dl_shared_object_no_ext = $dl_shared_object;
    # remove .so, xs.dll .dll, etc
    while ($dl_shared_object_no_ext =~ s/\.[^\/\.]+$//) {
      1;
    }
    if ($dl_shared_object_no_ext =~ /\Q$shared_lib_file_tail\E$/) {
      $shared_lib_file = $dl_shared_object;
      last;
    }
  }
  
  return $shared_lib_file;
}

sub search_native_address {
  my ($shared_lib_file, $sub_abs_name) = @_;
  
  my $native_address;
  
  if ($shared_lib_file) {
    my $dll_libref = DynaLoader::dl_load_file($shared_lib_file);
    if ($dll_libref) {
      my $sub_abs_name_c = $sub_abs_name;
      $sub_abs_name_c =~ s/:/_/g;
      $native_address = DynaLoader::dl_find_symbol($dll_libref, $sub_abs_name_c);
    }
    else {
      return;
    }
  }
  else {
    return;
  }
  
  return $native_address;
}

sub get_sub_native_address {
  my $sub_abs_name = shift;
  
  my $package_name;
  my $sub_name;
  if ($sub_abs_name =~ /^(?:(.+)::)(.+)$/) {
    $package_name = $1;
    $sub_name = $2;
  }
  
  my $dll_package_name = $package_name;
  my $shared_lib_file = _get_dll_file($dll_package_name);
  my $native_address = search_native_address($shared_lib_file, $sub_abs_name);
  
  # Try runtime compile
  unless ($native_address) {
    
    my $module_name = $package_name;
    $module_name =~ s/^SPVM:://;
    my $module_dir = get_use_package_path($module_name);
    $module_dir =~ s/\.spvm$//;
    
    my $module_name_slash = $package_name;
    $module_name_slash =~ s/::/\//g;
    
    $module_dir =~ s/$module_name_slash$//;
    $module_dir =~ s/\/$//;
    
    my $shared_lib_file = SPVM::Build::build_shared_lib(
      module_dir => $module_dir,
      module_name => "SPVM::$module_name"
    );
    if ($shared_lib_file) {
      $native_address = search_native_address($shared_lib_file, $sub_abs_name);
    }
  }
  
  return $native_address;
}

sub bind_native_subs {
  my $native_func_names = get_native_sub_names();
  for my $native_func_name (@$native_func_names) {
    my $native_func_name_spvm = "SPVM::$native_func_name";
    my $native_address = get_sub_native_address($native_func_name_spvm);
    unless ($native_address) {
      confess "Can't find native address($native_func_name())";
    }
    bind_native_sub($native_func_name, $native_address);
  }
}

# Compile SPVM source code just after compile-time of Perl
CHECK {
  require XSLoader;
  XSLoader::load('SPVM', $VERSION);
  
  # Load standard library
  my @dll_file_bases = ('std', 'Math');
  for my $shared_lib_file_base (@dll_file_bases) {
    my $shared_lib_file_rel = "auto/SPVM/$shared_lib_file_base.native/$shared_lib_file_base.$Config{dlext}";
    for my $module_dir (@INC) {
      my $shared_lib_file = "$module_dir/$shared_lib_file_rel";
      if (-f $shared_lib_file) {
        DynaLoader::dl_load_file($shared_lib_file);
        push @DynaLoader::dl_shared_objects, $shared_lib_file;
      }
    }
  }
  
  # Compile SPVM source code
  compile();
  
  # Build run-time
  build_runtime();
  
  # Free compiler
  free_compiler();
  
  # Compile extension native subroutine
  # compile_extension_native_subs();
  
  # Bind native subroutines
  bind_native_subs();
  
  # Build SPVM subroutine
  build_spvm_subs();
}

sub new_byte_array_data {
  my $string = shift;
  
  my $array = SPVM::Array::Byte->new_data($string);
  
  return $array;
}

sub new_byte_array_string {
  my $string = shift;
  
  # Encode internal string to UTF-8 string
  Encode::encode('UTF-8', $string);
  
  my $array = SPVM::Array::Byte->new_data($string);
  
  return $array;
}

sub new_byte_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::Array::Byte->new($length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_byte_array_len {
  my $length = shift;
  
  my $array = SPVM::Array::Byte->new($length);
  
  return $array;
}

sub new_short_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::Array::Short->new($length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_short_array_len {
  my $length = shift;
  
  my $array = SPVM::Array::Short->new($length);
  
  return $array;
}

sub new_int_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::Array::Int->new($length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_int_array_len {
  my $length = shift;
  
  my $array = SPVM::Array::Int->new($length);
  
  return $array;
}

sub new_long_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::Array::Long->new($length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_long_array_len {
  my $length = shift;
  
  my $array = SPVM::Array::Long->new($length);
  
  return $array;
}

sub new_float_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::Array::Float->new($length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_float_array_len {
  my $length = shift;
  
  my $array = SPVM::Array::Float->new($length);
  
  return $array;
}

sub new_double_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::Array::Double->new($length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_double_array_len {
  my $length = shift;
  
  my $array = SPVM::Array::Double->new($length);
  
  return $array;
}

sub new_object_array_len {
  my ($type_name, $length) = @_;
  
  my $array = SPVM::Array::Object->new($type_name, $length);
  
  return $array;
}

sub new_object {
  my $package_name = shift;
  
  my $object = SPVM::Object->new_object($package_name);
  
  return $object;
}

sub build_spvm_subs {
  my $sub_names = get_sub_names();
  
  for my $abs_name (@$sub_names) {
    # Define SPVM subroutine
    no strict 'refs';
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

1;

=encoding UTF-8

=head1 NAME

SPVM - Fast calculation, GC, static typing, VM with perlish syntax

B<SPVM is under development! I will change implementation and specification without warnings.>

=head1 SYNOPSIS

  use FindBin;
  use lib "$FindBin::Bin/lib";

  use SPVM 'MyModule2';

  my $total = SPVM::MyModule2::foo(3, 5);
  print $total . "\n";

Module file

  # lib/SPVM/MyModule1.spvm
  package MyModule1 {
    has x : int;
    has y : int;

    sub sum ($x : int, $y : int) : int {

      my $total = $x + $y;

      return $total;
    }
  }

  # lib/SPVM/MyModule2.spvm
  use MyModule1;
  package MyModule2 {

    sub foo ($x : int, $y : int) : int {

      my $total = ($x * $y) + MyModule1::sum(2, 4);

      return $total;
    }
  }

If you want to know more syntax, see C<solo/SPVM/Test.spvm>.

If you want to know SPVM language, see C<solo/README.md>

=head1 DESCRIPTION

Do you need B<faster Perl>? SPVM provides fast calculation to Perl.

=over 4

=item *

B<Fast calculation> - The Perl's biggest weak point is the calculation performance. SPVM provides fast calculations.

=item *

B<GC> - You don't need to care about freeing memory

=item *

B<Static typing> - Static typing for performance

=item *

B<VM> - Byte codes are generated so that you can run them on SPVM language

=item *

B<Perlish syntax> - SPVM syntax is very similar to Perl

=item *

B<Perl module> - SPVM function can be called from Perl itself.

=back

=head1 SPVM Tutorial

L<SPVM> is a language which is similar with Perl. SPVM is very similar to Perl, and you can write same syntax of Perl in most part.

L<SPVM> communicate with Perl. You can call SPVM function directory from Perl.

L<SPVM> is very fast and provide array data structure. Now SPVM array operation is about 6x faster.

=head2 SPVM module

At first, you can write SPVM module. 

  # lib/SPVM/MyModule1.spvm
  package MyModule1 {
    has x : int;
    has y : int;

    sub sum ($x : int, $y : int) : int {

      my $total = $x + $y;

      return $total;
    }
  }

This is same as Perl except SPVM have static type and C<has> keyword.

You can define field by C<has> keyword, and specify static type by C<: type>.

  has x : int;

You can specify argument types and return type to subroutine by C<: type>.

  sub sum ($x : int, $y : int) : int {

    my $total = $x + $y;

    return $total;
  }

Let's save this file by the following name

  lib/SPVM/MyModule1.spvm

If package name is C<MyModule1>, file name must be C<SPVM/MyModule1.spvm>.

Extension is C<spvm>. And you create C<SPVM> directory.

C<lib> is normal directory.

=head2 Call SPVM subroutine

Next you can use SPVM subroutine from Perl.

  use FindBin;
  use lib "$FindBin::Bin/lib";

  use SPVM 'MyModule1';

  my $total = SPVM::MyModule1::sum(3, 5);
  print $total . "\n";

At first, you add library path by L<FindBin> and L<lib> module.

  use FindBin;
  use lib "$FindBin::Bin/lib";

Next, use SPVM module. C<MyModule1> is loaded.

  use SPVM 'MyModule1';

And call SPVM subroutine. If SPVM subroutine absolute name is C<MyModule1::sum>, you can call this subroutine by C<SPVM::MyModule1::sum>.

  my $total = SPVM::MyModule1::sum(3, 5);
  print $total . "\n";

=head1 Document

=head2 SPVM Language Specification

L<SPVM::Document::Spec> - SPVM Language Specification

=head2 SPVM Native API

L<SPVM::Document::NativeAPI> - SPVM Native API.

Native API is C level API. You can write programing logic using C language and SPVM Native API.

=head2 SPVM Cookbook

L<SPVM::Document::Cookbook> - SPVM Cookbook, advanced technique and many examples.

=head2 SPVM FAQ

L<SPVM::Document::FAQ> - Oftten asked question.

=head1 Functions

=head2 new_byte_array

Create byte array.

  my $array = SPVM::new_byte_array([1, 2, 3]);

If you get perl values, you can use C<get_elements> methods.

  my $values = $array->get_elements;

=head2 new_byte_array_data

Create byte array from B<not decoded> Perl string.
This function is faster than C<new_byte_array_string> because the data is not encoded.

  my $array = SPVM::new_byte_array_data("AGTCAGTC");

=head2 new_byte_array_string

Create byte array from B<decoded> Perl string.

  my $array = SPVM::new_byte_array_string("あいうえお");

=head2 new_short_array

Create short array

  my $array = SPVM::new_short_array([1, 2, 3]);

If you get perl values, you can use C<get_elements> methods.

  my $values = $array->get_elements;

=head2 new_int_array

Create int array

  my $array = SPVM::new_int_array([1, 2, 3]);

If you get perl values, you can use C<get_elements> methods.

  my $values = $array->get_elements;

=head2 new_long_array

Create long array

  my $array = SPVM::new_long_array([1, 2, 3]);

If you get perl values, you can use C<get_elements> methods.

  my $values = $array->get_elements;

=head2 new_float_array

Create float array

  my $array = SPVM::new_float_array([1, 2, 3]);

If you get perl values, you can use C<get_elements> methods.

  my $values = $array->get_elements;

=head2 new_double_array

Create double array

  my $array = SPVM::new_double_array([1, 2, 3]);

If you get perl values, you can use C<get_elements> methods.

  my $values = $array->get_elements;
  
=head2 new_object_array_len

Create object array with type name and length.

  my $array = SPVM::new_object_array_len("int[]", 3);

You can set and get elements by C<set> and C<get> method.

  $array->set(1, SPVM::new_int_array([1, 2, 3]));
  my $element = $array->get(1);

=head2 new_object

Create object.

  my $object = SPVM::new_object("Point");

You can set and get value by C<set> and C<get> method.

  $object->set(x => 1);
  my $x = $object->get('x');

=head1 DON'T PANIC!

We are constantly working on new documentation. Follow us on
L<GitHub|https://github.com/yuki-kimoto/SPVM> or join the official IRC channel C<#perl11>
on C<irc.perl.org> to get all the latest updates.

=head2 SUPPORT

If you have any questions the documentation might not yet answer, don't
hesitate to ask on the the official IRC
channel C<#perl11> on C<irc.perl.org>
(L<chat now!|https://chat.mibbit.com/?channel=%23perl11&server=irc.perl.org>).

You can see #perl11 log.

L<http://irclog.perlgeek.de/perl11/>

=head1 AUTHOR

Yuki Kimoto E<lt>kimoto.yuki@gmail.com<gt>

=head1 CONTRIBUTERS

=over 4

=item *

L<akinomyoga|https://github.com/akinomyoga> (Koichi Murase)

=item *

L<[NAGAYASU Shinya|https://github.com/nagayasu-shinya>

=item *

L<Reini Urban|https://github.com/rurban>

=item *

L<chromatic|https://github.com/chromatic>

=item *

L<Kazutake Hiramatsu|https://github.com/kazhiramatsu>

=back

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2017 by Yuki Kimoto

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.16.3 or,
at your option, any later version of Perl 5 you may have available.

=cut
