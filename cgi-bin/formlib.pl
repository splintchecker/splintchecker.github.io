#!/usr/local/bin/perl
#
#   bjellis perl library for www
#
#   copyright 1994 Brigitte Jellinek, available under the Gnu Public License
#
#   Author: Brigitte Jellinek
#   e-mail: bjelli@cosy.sbg.ac.at
#   URL:    http://www.cosy.sbg.ac.at/people/bjelli.html
# 
#   Version: 0.0  -  Wed Dec 29 1993
#
#   Description:  there subroutines that help you parse the information
#                 passed from a FORM
#
#   Usage:  call one of the subroutines to parse the information, then
#           read the resulte from %in: e.g. the enty in an input-field
#           with name 'color' can be found as $in{'color'}.  The total
#           number of argument found can be read from $noin.
#
#    &GetFormArgs: for both GET and POST
#    &GetPostArgs: for Method POST
#    &GetGetArgs:  for Method GET
#
#    &GetPathArgs: parses a string of the form name=value/name=value/...
#           
#    &HtmlError(program, admin, text):  gives an error message in html, exits.
############################################################################

%in = ();

sub GetFormArgs
#
#  decides wether GET or POST was used, otherwise gives an error code
#
    {
    if (   $ENV{REQUEST_METHOD} eq 'POST' 
        && $ENV{CONTENT_TYPE}   eq 'application/x-www-form-urlencoded')
        {
        &GetPostArgs();
        }
    elsif (   $#ARGV == -1  &&  $ENV{REQUEST_METHOD} eq 'GET' 
           && $ENV{QUERY_STRING} ne '')
        {
        &GetGetArgs();
        }
    else
        {
        &HtmlError('GetFormArgs', 
                   'whoever wrote the script youre using',
                   'this script needs to be called from a FORM,
                    either by POST or GET.');
        };
    1;
    }

sub GetPostArgs
#
#  reads $ENV{CONTENT_LENGTH} bytes from STDIN, (assumed to be urlencoded)
#  and parses them with &parse
#
    {
    unless( $ENV{REQUEST_METHOD} eq 'POST' 
        &&  $ENV{CONTENT_TYPE}   eq 'application/x-www-form-urlencoded')
          { &HtmlError('GetPostArgs', 
                   'whoever wrote the script youre using',
                   'this script needs to be called from a FORM,
                    using method POST.');
          };
    read(
    STDIN, 
    $a, 
    $ENV{CONTENT_LENGTH});

    &parse($a,'&');
    };

sub GetGetArgs
#
#  reads the Arguments from the string $ENV{QUERY_STRING}, assumes that they
#  are urlencoded, and parses them with &parse
#
    {
    unless($#ARGV == -1  &&  $ENV{REQUEST_METHOD} eq 'GET' 
        && $ENV{QUERY_STRING} ne '')
          { &HtmlError('GetPostArgs', 
                   'whoever wrote the script youre using',
                   'this script needs to be called from a FORM,
                    using method GET.');
          };
    $a = $ENV{QUERY_STRING};
    &parse($a,'&');
    };

sub GetPathArgs
#
#  parses its one argument, a string of the from {/name=value}
#
    {
    local($pathstring) = @_;

    $pathstring =~ s!^/!!;


    &parse($pathstring,'/');
    };

sub parse
#
# parses urlencoded input its only argument (a string)
# returns values in the global variables %in and $noin
#
    {
    local($argstring,$splitcharacter) = @_;

    foreach (split("$splitcharacter", $argstring))    
     { if (/(.*)=(.*)/)  
          {
          ($nam, $val) = ($1, $2);
          $val =~ s/\+/ /g ;
          $val =~ s/%(..)/pack('c',hex($1))/eg;  # unescape characters
          if (defined $in{$nam})
              {       
              $in{$nam} .= "#" . $val
              } 
          else
              {
              $in{$nam} = $val;                
              };
         }
         else
         {
         &HtmlError("formlib.parse", "bjelli", 
                    "Error parsing $_, aborting.\n");
         };
     };
    @k = keys(%in);                # I couldn't find a better way of counting
    $noin = $#k; $noin++;          # entries in %in.  do YOU know one?

    };


sub HtmlError
#
# 
#
#
    {
    local($program, $admin, $text) = @_;

    print <<"EOM";
Content-Type: text/html


<TITLE>Error in '$program'</TITLE> 

<H1>Error in '$program'</H1> 

$text
<P> 
<HR> 
if you need help, call $admin.

EOM
    exit 1;
    };
                                     



    1;
               
