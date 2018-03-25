#!/usr/local/bin/perl
require "formlib.pl";

$timestamp = gmtime;


open(STATUS, "echo $timestamp |")                      || die "can't fork: $!";
while (<STATUS>) {
    print;
} 
print "Test Finished\n";
