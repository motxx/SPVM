package SPVM::PerlAPI;

use Carp 'croak', 'confess';

sub new_byte_array {
  my ($env, $elements) = @_;
  
  return undef unless defined $elements;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::PerlAPI::new_byte_array_len($env, $length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_byte_array_string {
  my ($env, $string) = @_;
  
  # Encode internal string to UTF-8 string
  my $bin = Encode::encode('UTF-8', $string);
  
  my $length = length $bin;
  
  my $array = SPVM::PerlAPI::new_byte_array_len($env, $length);
  $array->set_bin($bin);
  
  return $array;
}

sub new_short_array {
  my ($env, $elements) = @_;

  return undef unless defined $elements;

  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::PerlAPI::new_short_array_len($env, $length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_int_array {
  my ($env, $elements) = @_;

  return undef unless defined $elements;

  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::PerlAPI::new_int_array_len($env, $length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_long_array {
  my ($env, $elements) = @_;

  return undef unless defined $elements;

  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::PerlAPI::new_long_array_len($env, $length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_float_array {
  my ($env, $elements) = @_;

  return undef unless defined $elements;

  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::PerlAPI::new_float_array_len($env, $length);
  
  $array->set_elements($elements);
  
  return $array;
}

sub new_double_array {
  my ($env, $elements) = @_;
  
  return undef unless defined $elements;
  
  if (ref $elements ne 'ARRAY') {
    confess "Argument must be array reference";
  }
  
  my $length = @$elements;
  
  my $array = SPVM::PerlAPI::new_double_array_len($env, $length);
  
  $array->set_elements($elements);
  
  return $array;
}

1;
