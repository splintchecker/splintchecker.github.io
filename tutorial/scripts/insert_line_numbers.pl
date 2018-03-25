#!/usr/bin/perl
@lines=<STDIN>;
for($i = 0; $i <= $#lines; $i++)
{
  print '/*';
  print $i+1;
  print '*/';
  print "\t";
  print $lines[$i];
}

