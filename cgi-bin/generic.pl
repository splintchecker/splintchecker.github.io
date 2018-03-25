#!/usr/local/bin/perl
#
# copyright meng weng wong <mengwong@seas.upenn.edu>
# freely distributable under the terms of the gnu public license
# version 2.0
# this perl program will do basically the same thing as
# post-query, only it's written in perl, not hexadecimal.
# see http://www.seas.upenn.edu/~mengwong/forms/
################################################## initialization

# set this to your cgi-bin directory
push(@INC,"/export/home/httpd/cgi-bin");
require 'cgi-lib.pl';

@httpdenv = (
	     AUTH_TYPE,
	     CONTENT_LENGTH,
	     CONTENT_TYPE,
	     DOCUMENT_ROOT,
	     GATEWAY_INTERFACE,
	     HTTP_ACCEPT,
	     HTTP_USER_AGENT,
	     PATH,
	     PATH_INFO,
	     PATH_TRANSLATED,
	     QUERY_STRING,
	     REMOTE_ADDR,
	     REMOTE_HOST,
	     REMOTE_IDENT,
	     REMOTE_USER,
	     REQUEST_METHOD,
	     SCRIPT_NAME,
	     SERVER_NAME,
	     SERVER_PORT,
	     SERVER_PROTOCOL,
	     SERVER_SOFTWARE,
	     );

################################################## get input

&ReadParse;
print &PrintHeader;

print <<"header";
<TITLE>Done!</TITLE>

<h2>Welcome to <a href="http://www.sds.lcs.mit.edu/~hari/6.896">6.896: Topics in Computer Networks</a>!</h2>

<h2>    $in{NAME}</h2>

Your information has been added to the class roster. <br>

header
print "<HR><DL>\n";
foreach $key (keys %in) {
    print "<DT> <b>", $key, "</b>\n<DD>", $in{$key}, "\n";
}
print "</DL><HR><p>";
print "<a href=http://www.sds.lcs.mit.edu/~hari> Hari Balakrishnan </a>\n";

## the following will print variables to a log file.
## in theory.  because i haven't actually tested it.

# open a logfile for appending, will stick stuff on the end.
open (LOGFILE, ">>/export/home/httpd/htdocs/6.896/roster.txt");

# loop through the list of key/value pairs
# and write each pair to the logfile. will break on multiple values.

foreach $key (keys %in)
{ print LOGFILE "$key=$in{$key}\t"; }

print LOGFILE "\n";

# and close the logfile.
close LOGFILE








