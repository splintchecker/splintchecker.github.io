<html>
<head>
<title>Floating Point Comparision</title>
</head>
<body>

<p>
If you compare two floating point numbers, the actual difference
may be smaller than the smallest possible floating point the computer
can recognize. In this case, the program would say the numbers
are equal when mathematically they differ:

<code><pre><?php include("DangerousFloat.c"); ?></code></pre>


In this case the computer cannot distinguish 10<sup>-1000</sup>
from 0. 

<p>
For our Body Mass Index example, it is probably okay since 
we aren't very concerned with absolute precision. However,
it was an error similar to this which caused a 
<A HREF="http://www.cs.unc.edu/~dm/UNC/COMP205/LECTURES/ERROR/lec23/node4.html">
Patriot Missile to miss a Scud during the Gulf War.</A>

</body>
</html>









