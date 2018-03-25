#!/usr/bin/perl
$start_pattern = $ARGV[0];
$end_pattern = $ARGV[1];
@lines = <STDIN>;
chomp(@lines);
$i = 0;

while ($lines[$i] ne $start_pattern) 
{
    $i++;
    if ($i > $#lines) 
    {	
	die("Pattern $start_pattern not found");
    }
}
$i++;

while($lines[$i] ne $end_pattern)
{
    print $lines[$i]; print "\n";
    $i++;
    if ($i > $#lines)
    {
	die("Pattern $end_pattern not found");
    }
}

 
