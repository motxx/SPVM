use strict;
use warnings;
use FindBin;
use lib "$FindBin::Bin/lib";
use Benchmark qw/timethese cmpthese/;

use SPVM 'MySin';

# Initialize SPVM

my $bench_count = 100;

my $array_count = 1000000;
my $perl_array_input  = [ (3.14,) x $array_count ];
my $perl_array_output = [ (0.00,) x $array_count ];

my $spvm_array_input  = SPVM::new_double_array($perl_array_input);
my $spvm_array_output = SPVM::new_double_array($perl_array_output);
my $spvm_array_input_precompile  = SPVM::new_double_array($perl_array_input);
my $spvm_array_output_precompile = SPVM::new_double_array($perl_array_output);
my $spvm_array_input_native      = SPVM::new_double_array($perl_array_input);
my $spvm_array_output_native     = SPVM::new_double_array($perl_array_output);

my ($expected, $eps) = (0.00159265, 1e-5);

my $result = timethese($bench_count, {
  perl5_27_sin => sub {
    perl_sin($perl_array_input, $perl_array_output, $array_count);
  },
  spvm_sin => sub {
    MySin->spvm_sin($spvm_array_input, $spvm_array_output, $array_count);
  },
  spvm_sin_precompile => sub {
    MySin->spvm_sin_precompile($spvm_array_input_precompile, $spvm_array_output_precompile, $array_count);
  },
  spvm_sin_native => sub {
    MySin->spvm_sin_native($spvm_array_input_native, $spvm_array_output_native, $array_count);
  },
});

check_output(@$perl_array_output);
check_output(@{$spvm_array_output->to_elems});
check_output(@{$spvm_array_output_precompile->to_elems});
#check_output(@{$spvm_array_output_native->to_elems});

cmpthese $result;

print "---------------\n";
my $x = $spvm_array_output_native->to_elems;
print "correct val: " . $x->[12345], "\n";
print "output size: " . @$x, "\n";
print "zeroval: " . (join ', ', grep { !($expected - $eps <= $_ && $_ <= $expected + $eps) } @{$spvm_array_output_native->to_elems}) . "\n";
print "index: " . (join ', ', map { $x->[$_ - 1] == 0 ? $_ : () } (1 .. $array_count) ) . "\n";

sub perl_sin {
  my ($input, $output, $count) = @_;
  
  my $total = 0;
  for (my $i = 0; $i < $count; $i++) {
    $output->[$i] = sin($input->[$i]);
  }
}

sub check_output {
  die unless (grep { $expected - $eps <= $_ && $_ <= $expected + $eps } @_) == $array_count;
}

=head1 Benchmark result
