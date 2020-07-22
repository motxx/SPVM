use strict;
use warnings;
use FindBin;
use lib "$FindBin::Bin/lib";

use SPVM 'TestArray';

my $perl_array = [];
$perl_array->[$_] = $_ + 1 for 0 .. 4;
print "perl_array: ";
print join(' ', @$perl_array), "\n";

my $spvm_array = SPVM::new_double_array($perl_array);
print "spvm_array: ";
print join(' ', @{$spvm_array->to_elems}), "\n";

TestArray->test($spvm_array, scalar @$perl_array);
