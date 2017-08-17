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
use SPVM::String;
use SPVM::Array::Object;

use Encode 'encode';

use Carp 'croak';

our $VERSION = '0.0246';

our $COMPILER;
our @PACKAGE_INFOS;
our %PACKAGE_SYMTABLE;
our %FIELD_SYMTABLE;
our %SUB_SYMTABLE;
our $API;
our @TYPE_NAMES;
our %TYPE_SYMTABLE;

sub _get_dll_file {
  my $module = shift;
  
  # DLL file name
  my $dlext = $Config{dlext};
  my $dll_base_name = __PACKAGE__ . ".$dlext";
  $dll_base_name =~ s/^.*:://;
  my $dll_file_tail = 'auto/' . __PACKAGE__ . '/' . $dll_base_name;
  $dll_file_tail =~ s/::/\//g;
  my $dll_file;
  for my $dl_shared_object (@DynaLoader::dl_shared_objects) {
    if ($dl_shared_object =~ /\Q$dll_file_tail\E$/) {
      $dll_file = $dl_shared_object;
      last;
    }
  }
  
  return $dll_file;
}

# Compile SPVM source code just after compile-time of Perl
CHECK {
  require XSLoader;
  XSLoader::load('SPVM', $VERSION);
  
  # Compile SPVM source code
  compile();
  
  my $dll_file = _get_dll_file(__PACKAGE__);
  
  # my $spvm_dll = DynaLoader::dl_load_file(
  
  # Build type names
  build_type_names();

  # Build type names
  build_type_symtable();
  
  # Build subroutine symbol table
  build_sub_symtable();
  
  # Build package symbol table
  build_package_symtable();
  
  # Build field symbol table
  build_field_symtable();
  
  # Build SPVM subroutine
  build_spvm_subs();
  
  # Build run-time
  build_runtime();
  
  # Free compiler
  free_compiler();
}
sub new_string_raw {
  my $string = shift;
  
  my $array = SPVM::String->new_raw($string);
  
  return $array;
}

sub new_string {
  my $string = shift;
  
  $string = Encode::encode('UTF-8', $string);
  
  my $array = SPVM::String->new_raw($string);
  
  return $array;
}

sub new_byte_array {
  my $elements = shift;
  
  if (ref $elements ne 'ARRAY') {
    croak "Argument must be array reference";
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
    croak "Argument must be array reference";
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
    croak "Argument must be array reference";
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
    croak "Argument must be array reference";
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
    croak "Argument must be array reference";
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
    croak "Argument must be array reference";
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

my $package_names_h = {};

sub import {
  my ($class, $package_name) = @_;
  
  # Add package infomations
  if (defined $package_name) {
    unless ($package_names_h->{$package_name}) {
      my ($file, $line) = (caller)[1, 2];

      my $package_info = {
        name => $package_name,
        file => $file,
        line => $line
      };
      push @PACKAGE_INFOS, $package_info;
      
      $package_names_h->{$package_name} = 1;
    }
  }
}

sub build_spvm_subs {
  for my $abs_name (keys %SUB_SYMTABLE) {
    
    # Define SPVM subroutine
    no strict 'refs';
    *{"SPVM::$abs_name"} = sub {
      my $return_value;
      eval { $return_value = SPVM::call_sub("$abs_name", @_) };
      croak $@ if $@;
      $return_value;
    };
  }
}


# Preloaded methods go here.

1;
__END__
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

    sub sum ($a : int, $b : int) : int {

      my $total = $a + $b;

      return $total;
    }
  }

  # lib/SPVM/MyModule2.spvm
  use MyModule1;
  package MyModule2 {

    sub foo ($a : int, $b : int) : int {

      my $total = ($a * $b) + MyModule1::sum(2, 4);

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

SPVM only work on the Perl which support 64 bit integer.

=head1 DOCUMENT

=over 2

=item 1

L<SPVM::Document::Tutorial> - SPVM Tutorial

=item 2

L<SPVM::Document::PerlAPI> - API to exchange Perl value to SPVM value.

=item 3

L<SPVM::Document::Specification> - SPVM Specification

=back

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
