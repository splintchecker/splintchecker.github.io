#!/usr/bin/perl
$start_line = $ARGV[0];
$end_line = $ARGV[1];

@lines=<STDIN>;
for($i = $start_line - 1; $i <= $end_line - 1; $i++)
{
    print $lines[$i];
}

