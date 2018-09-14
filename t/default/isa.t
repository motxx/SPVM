use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More 'no_plan';

use SPVM 'TestCase::Isa';

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# isa
{
  ok(TestCase::Isa->isa_basic());
}

# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);
