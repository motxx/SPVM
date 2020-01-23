use lib "t/lib";
use TestAuto;

use strict;
use warnings;

use Test::More 'no_plan';

use SPVM 'TestCase::Lib::SPVM::IO::File';

use TestFile;

# Start objects count
my $start_memory_blocks_count = SPVM::get_memory_blocks_count();

# Copy test_files to test_files_tmp with replacing os newline
TestFile::copy_test_files_tmp_replace_newline();

my $test_dir = "$FindBin::Bin/..";
{
  # open
  {
    my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
    ok(TestCase::Lib::SPVM::IO::File->test_open($sp_file));
  }
  
  # read
  {
    my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
    ok(TestCase::Lib::SPVM::IO::File->test_read($sp_file));
  }

  # readline
  {
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline($sp_file));
    }
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_while($sp_file));
    }
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/file_eof.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_eof($sp_file));
    }
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/long_line.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_long_line($sp_file));
    }
  }
  
  # readline and chomp_lf
  {
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_chomp_lf($sp_file));
    }
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_chomp_lf_while($sp_file));
    }
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/file_eof.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_chomp_lf_eof($sp_file));
    }
    {
      my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/long_line.txt");
      ok(TestCase::Lib::SPVM::IO::File->test_readline_chomp_lf_long_line($sp_file));
    }
  }

  # slurp
  {
    my $sp_file = SPVM::new_string("$test_dir/test_files_tmp/fread.txt");
    ok(TestCase::Lib::SPVM::IO::File->test_slurp($sp_file));
  }
}


# All object is freed
my $end_memory_blocks_count = SPVM::get_memory_blocks_count();
is($end_memory_blocks_count, $start_memory_blocks_count);
