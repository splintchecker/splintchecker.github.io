#!/usr/bin/perl -w

#$num =  @ARGV;
#print "$num \n";
#die ($num == 3," @ARGV" );

($file1, @ARGV) = @ARGV;
($file2, @ARGV) = @ARGV;

$run = "sed  's/ <a href=\"#_ftn\([0123456789]*\)\"/<a href=\"appNotes.html#_ftn\1\"/g' ";
#join(" ",@ARGV);
chomp($run);
$run = "$run $file1  >$file2";
print $run;
print ";\n";
system "$run";
#print "\n";
#print "RAN $run \n";
