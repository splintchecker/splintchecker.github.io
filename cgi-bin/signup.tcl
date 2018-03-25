#! /opt/bin/tclsh

#
# Web signup for 6.896: Topics in Computer Networks
# Fall 1998 (http://www.sds.lcs.mit.edu/~hari/6.896)
# Hari Balakrishnan (hari@lcs.mit.edu)
#

# Skip the SMTP header
while { [gets stdin line] >= 0 } {
  puts "Line: $line"
  if { [string first "START_RECORD=" $line] >= 0} {
    break;
  }
}

# Parse current record into 'key=value' pairs.
set kvpairs [split $line "&"]

# Prepare output file for dump table.

set dump "<TR>\n"

set n [llength $kvpairs]
for {set i 0} {$i < $n} {incr i} {
    set pair  [lindex $kvpairs $i]
    set k     [lindex [split $pair "="] 0]
    set v     [lindex [split $pair "="] 1]
    set fields [split $v "+"]
    set nf [llength $fields]

    # The real '+' is converted to %2B
    for {set j 0} {$j < $nf} {incr j} {
      if {[lindex $fields $j] == "%2B"} {
	set fields [lreplace $fields $j $j "+"]
      }      
    }
    set display [join $fields]
 
    # Ignore the start-of-record marker. 
    if {$k != "START_RECORD"} {
      set dump "$dump \t <TD> $display </TD> \n"
    }
}

set dump "$dump </TR>\n\n"
set fd [open /home/salsa/suchi/public_html/tmp/list.html a+]
puts $fd $dump
#puts $fd $line
close $fd




