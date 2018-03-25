#!/usr/local/bin/perl
require "formlib.pl";

&GetFormArgs;

print "Content-Type: text/html\n\n";

print "<TITLE>Subscription Success</TITLE>\n";
print "<H1>Success</H1>\n";

open (SUBS, ">>lclint-announce-new") or
print "<b>Error: cannot open subscription file.</b>\n";
print SUBS "$in{email}\n";

print "You have subscribed to the lclint-announce mailing list as ";
print "<em>$in{email}</em>.<p>\n";   
print "<p></br>\n";

print "You will receive announcements regarding lclint releases.";
print "<p><p><hr>\n";


