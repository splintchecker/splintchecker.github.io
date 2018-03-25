# File: parseform.pl 
# This subroutine takes a url-encoded string and 
# turns it into an associative array. 
sub parseform 
{ 
   local($formthing) = @_; 
   
   # Expects something like: 
   # foo=wow%21&bar=hello&baz=blah 
   
   # Split the string into each of the key-value pairs 
   (@fields) = split('&', $formthing); 
   
   # For each of these key-value pairs, decode the value 
   for $field (@fields) 
   { 
   
     # Split the key-value pair on the equal sign. 
     ($name, $value) = split('=', $field); 
   
     # Change all plus signs to spaces. This is an 
     # remnant of ISINDEX 
     $value =~ y/\+/ /; 
   
     # Decode the value & removes % escapes. 
     $value =~ s/%([\da-f]{1,2})/pack(C,hex($1))/eig; 
   
     # Create the appropriate entry in the 
     # associative array lookup 
     if(defined $lookup{$name}) 


     { 
       # If there are multiple values, separate 
       # them by newlines 
       $lookup{$name} .= "\n".$value; 
     } 
 else 
     { 
       $lookup{$name} = $value; 
     } 
   } 
   
   # Return the associative array 
   %lookup; 
} 
   
# Always do this for files that you "require" 
1; 

