<html>
<head>
<title>Your First C Program</title>
</head>
<body>

<h1> A First C Program </h1>
<h3> Overview </h3>
The section gets you started working with
C and familiar with the basic syntax, of compiling and running 
C programs. 



<h3> Get Started </h3>

<p>
Let's get started with a very simple C program. This program 
will just output the string HelloWorld:



<pre><code>
<!--#include virtual="HelloWorld.c"-->
</pre></code>

<p>
Start the editor, and enter the text as it is written
above, but don't cut and paste. The goal here is to just
get accustomed to the syntax. 

<p>
Save the file as
<code> HelloWorld.c </code> 

Now you need to compile it. A compiler 
takes as input the source code you write, and 
produces machine code, which the computer 
can understand and execute. 

<p>
The most common compiler is <A
HREF=http://www.gnu.org/software/gcc/gcc.html>gcc</A>  
which you probably already have.  Try
<code> gcc --help</code>.

<h3> Compiling </h3>
<p> 
To compile open a terminal and enter: 

<code><pre>
gcc HelloWorld.c 
</code></pre> 

If you are having trouble compiling check the syntax of your code. 
Notice that every statement has to end with a semi-colon. Make sure 
you surround all the strings with double quotes. C is also
case sensitive so you will get an error if you enter "MAIN" instead
of "main".

Compilers aren't very forgiving
about syntax. If you do make a mistake, don't get discouraged.
Now is a good time to get familiar with what kinds of errors
produce what kinds of compiler output.


<h3> Running </h3>
<p>
Once you have compiled the program the next step is to run it. Type:
<code><pre>
a.out
</code></pre>

<p>
If you are using gcc and you want to call the output executable 
something else then enter: 

<pre><code>
dkf5k@paisley
: /uf5/dkf5k/testsource ; gcc HelloWorld.c -o hello

dkf5k@paisley
: /uf5/dkf5k/testsource ; hello
Hello World!
</pre></code>

After the -o flag enter whatever you want to call the executable
file. Note that if you compile a different source file and give
it the same name as an old executable the old executable will get
overwritten.
  

<h3> Examine the Source </h3>

What do you think the printf
statement does? 
<p>
a) Abort the program <p>
b) Display text on the screen <p>
c) Increment the accumulator register <p>
d) Begin an infinite loop <p>

You would probably guess that b) printf displays text on the screen. 
Knowing this you can add arbitrary text to your program. Try modifying
the HelloWorld program so that it greets you. Make it print "Hello
&lt;your_name&gt;".

<p>


Now look at the <code> return 0;</code>
statement. For now, all we need to know 
is that <code> return 0; </code> exits the program. Here's an
experiment for you to try. Take your HelloWorld program, and transpose
the <code> printf </code> statements, and the <code> return 0; </code>
statements, so that the <code> return 0; </code> statement is first. 
What do you think will happen? Try it and see. Then try putting 
some <code> printf </code> statements before the <code> return 0;
</code> statement.

<p>

Let's look at this part of the source code: 
<code><pre>
int main()
{
}
</code></pre>
For now, all we need to know is that there is some
<i> function </i> called <code> main </code> in our program. All C
programs must have some function specifically called <code>main</code>.
The <code> main </code> function is where execution starts. 

<p>
Now let's turn our attention to the line:
<pre><code>
/*My First C Program*/
</pre></code>

This is a <i> comment </i>. Comments are delimited
by /* and */. The compiler completely ignores 
them since their purpose is to aid a human 
reader. Somebody reading this 
file would know that the program is "My First C 
Program".


<p>
Another use for comments is to temporarily stop
blocks of code from being compiled. You might
only want to test part of your program, and 
by "commenting  out" the rest you can accomplish this. But
you cannot nest comments. 


<p>
The last lines of code that we haven't talked about are 
the <code> #include </code> statements. 

There is a file called stdlib.h (you can look
at this file if you would like it
will probably be in the <code> /usr/include </code> directory)
and the <code> #include </code> statement instructs the 
<i>preprocessor</i> to take the contents of that file and insert
it directly into the file being compiled. Here is an experiment 
for you to try: create a file and call it <code>message.txt </code>.
In the file put the following line:
<pre><code>
Welcome to the wondeful world of C!
</pre></code>
<p>
Then create another file and call it <code>test.c</code>.
<pre><code> 
<?php
    include("IncludeExperiment.c");
?>
</pre></code>


Compile and run the program with both the line <code>
#include "MySquare.inc" </code> compiled, and commented
out. In one case it will compile, and in the other 
case it will not. 

<p>
In the next section we will learn more about C's built in
types, and operators. 

<p>
<A HREF="../chapter2/chapter2.php"> Next </A>
<p>
<A HREF="../index.html">Contents </A>
</body>
</html>

 
 





























