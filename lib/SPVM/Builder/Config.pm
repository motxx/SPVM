package SPVM::Builder::Config;

use strict;
use warnings;
use Config;

sub new {
  my $class = shift;
  
  my $self = {};
  
  $self->{config} = {};

  return bless $self, $class;
}

sub set_src_ext {
  my ($self, $src_ext) = @_;
  
  $self->{src_ext} = $src_ext;
  
  return $self;
}

sub get_src_ext {
  my ($self) = @_;
  
  return $self->{src_ext};
}

sub replace_all_config {
  my ($self, $config) = @_;
  
  $self->{config} = $config;
}

sub to_hash {
  my $self = shift;
  
  my $hash_config = {%{$self->{config}}};
  
  return $hash_config;
}

sub get_config {
  my ($self, $name) = @_;
  
  return $self->{config}{$name};
}

sub set_config {
  my ($self, $name, $value) = @_;
  
  $self->{config}{$name} = $value;
  
  return $self;
}

sub set_ccflags {
  my ($self, $ccflags) = @_;
  
  $self->set_config(ccflags => $ccflags);
  
  return $self;
}

sub get_ccflags {
  my $self = shift;
  
  return $self->get_config('ccflags');
}

sub add_ccflags {
  my ($self, $new_ccflags) = @_;
  
  my $ccflags = $self->get_config('ccflags');
  
  $ccflags .= " $new_ccflags";
  
  $self->set_config('ccflags' => $ccflags);
  
  return $self;
}

sub set_std {
  my ($self, $spec) = @_;
  
  my $ccflags = $self->get_ccflags;
  
  # Remove -std=foo section
  $ccflags =~ s/-std=[^ ]+//g;
  
  $ccflags .= " -std=$spec";
  
  # Add -std=foo section
  $self->set_ccflags($ccflags);
  
  return $self;
}

sub set_cc {
  my ($self, $cc) = @_;
  
  return $self->set_config(cc => $cc);
}

sub get_cc {
  my ($self, $cc) = @_;
  
  return $self->get_config('cc');
}

sub set_optimize {
  my ($self, $optimize) = @_;
  
  return $self->set_config(optimize => $optimize);
}

sub get_optimize {
  my ($self, $optimize) = @_;
  
  return $self->get_config('optimize');
}

sub set_ld {
  my ($self, $ld) = @_;
  
  return $self->set_config(ld => $ld);
}

sub get_ld {
  my ($self, $ld) = @_;
  
  return $self->get_config('ld');
}

sub set_lddlflags {
  my ($self, $lddlflags) = @_;
  
  $self->set_config(lddlflags => $lddlflags);
  
  return $self;
}

sub get_lddlflags {
  my $self = shift;
  
  return $self->get_config('lddlflags');
}

sub add_lddlflags {
  my ($self, $new_lddlflags) = @_;
  
  my $lddlflags = $self->get_config('lddlflags');
  
  $lddlflags .= " $new_lddlflags";
  
  $self->set_config('lddlflags' => $lddlflags);
  
  return $self;
}

sub set_extra_compiler_flags {
  my ($self, $extra_compiler_flags) = @_;
  
  $self->set_config(extra_compiler_flags => $extra_compiler_flags);
  
  return $self;
}

sub get_extra_compiler_flags {
  my $self = shift;
  
  return $self->get_config('extra_compiler_flags');
}

sub add_extra_compiler_flags {
  my ($self, $new_extra_compiler_flags) = @_;
  
  my $extra_compiler_flags = $self->get_config('extra_compiler_flags');
  
  $extra_compiler_flags .= " $new_extra_compiler_flags";
  
  $self->set_config('extra_compiler_flags' => $extra_compiler_flags);
  
  return $self;
}

sub set_extra_linker_flags {
  my ($self, $extra_linker_flags) = @_;
  
  $self->set_config(extra_linker_flags => $extra_linker_flags);
  
  return $self;
}

sub get_extra_linker_flags {
  my $self = shift;
  
  return $self->get_config('extra_linker_flags');
}

sub add_extra_linker_flags {
  my ($self, $new_extra_linker_flags) = @_;
  
  my $extra_linker_flags = $self->get_config('extra_linker_flags');
  
  $extra_linker_flags .= " $new_extra_linker_flags";
  
  $self->set_config('extra_linker_flags' => $extra_linker_flags);
  
  return $self;
}

=head1 NAME

SPVM::Builder::Config - build config

=head1 DESCRIPTION

L<SPVM::Builder::Config> is configuration of c/c++ compile and link.

=head1 Methods

=head2 new

  my $build_config = SPVM::Builder::Config->new;
  
Create L<SPVM::Builder::Config> object.

=head2 replace_all_config

  my $config = {cc => 'g++', ld => 'g++'};
  $build_config->replace_all_config($config);

Replace all config.

All of old configs is removed and added new config.

=head2 to_hash

  my $config = $build_config->to_hash;

Convert configs to hash reference.

=head2 get_config

  my $cc = $build_config->get_config('cc');

Get a config value.

=head2 set_config

  $build_config->set_config(cc => $cc);

Set a config value.

=head2 set_ccflags

  $build_config->set_ccflags($ccflags);

Set C<ccflags>.

=head2 get_ccflags

  my $ccflags = $build_config->get_ccflags;

Get C<ccflags>.

=head2 add_ccflags

  $build_config->add_ccflags($ccflags);

Add C<ccflags> after current C<ccflags>.

=head2 set_std

  $build_config->set_std('c99');

Set C<std>.

Internally, remove C<-std=old> and add C<-std=new> after C<ccflags>.

=head2 set_cc

  $build_config->set_cc($cc);

Set C<cc>.

=head2 get_cc

  my $cc = $build_config->get_cc;

Get C<cc>.

=head2 set_optimize

  $build_config->set_optimize($optimize);

Set C<optimize>.

=head2 get_optimize

  my $optimize = $build_config->get_optimize;

Get C<optimize>.

=head2 set_ld

  $build_config->set_ld($ld);

Set C<ld>.

=head2 get_ld

  my $ld = $build_config->get_ld;

Get C<ld>.

=head2 set_lddlflags

  $build_config->set_lddlflags($lddlflags);

Set C<lddlflags>.

=head2 get_lddlflags

  my $lddlflags = $build_config->get_lddlflags;

Get C<lddlflags>.

=head2 add_lddlflags

  $build_config->add_lddlflags($lddlflags);

Add C<lddlflags> after current C<lddlflags>.

=cut

1;
