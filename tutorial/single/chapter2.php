<html> 
<head>
<title>Types and Operations</title>
</head>
<body>

<h1>Types and Operations</h1> 

<h2>Overview</h2>
In this section we introduce 
the basics of the C language while also introducing
some of the common mistakes people make 
which are usually not caught by the compiler. We
show you how to use Splint to find these kinds of mistakes. 

<h2>Types</h2>
So far in the first C program we saw the <code> int </code> type. 
There are four other basic types in the C Programming
Language:
<code><pre>

char        defined to be a single byte holding one character
int         an integer
float       a single precision floating point number
double      a double precision floating point number
void        the valueless type

</code></pre>
<p>
An <code>int</code> is simply a positive or negative
whole number. A float, or double is a number
with a decimal point like 3.14159 or 2.71828.

<p>
You can declare variables of a certain type like this:

<code><pre>
int max = 50;
int a,b,c,d,e;   /*declare five integer types*/
float PI = 3.14159;
double E = 2.71828;
char language = 'C';  /*declare and initialize two character types*/
</code></pre>



<p>
The '=' sign is the 
<i> assignment </i> operator. The line: 
<code><pre>
int max = 50;
</code></pre>

<p>
means the variable <code>max</code> gets the value 50.

<p>
Notice we can either initialize the variable
when we declare it, or we may not.
What happens if 
we use a variable that we have not initialized? 
Try compiling and running
the following program: 


<code><pre>
<!--#include virtual="Initialized.c"-->
</code></pre>

Here the <code>%d</code> indicates that the
bits associated with variable <code>a</code> should
be interpreted as an integer in printing.  

What will this program output?
It should output the value 5 since variable <code>a
</code> was initialized with the value
5. 

What would happen if we didn't initialize the variable? 

<code><pre>
<!--#include virtual="Uninitialized.c"-->
</code></pre>

Try compiling and running the program, and see what happens. 
You should get something like: 

<code><pre>
dkf5k@paisley
: /uf5/dkf5k/testsource ; a.out
The value of variable a is -1073744252
</code></pre>

Where did this -1073744252 number come from? It
is whatever happens to be on the stack . In general, 
using a variable whose value is uninitialized will lead to a buggy 
program. Notice that the compiler
silently produced an executable for you (even though the output is 
undefined, and the source code is probably wrong). 

<p>
Splint will tell you that something looks wrong.
Let's see how this works.

<p>
If you are using Emacs, create a new file (say <code> test.c </code>)
and, copy the above source code into it if you haven't done
so already. Then type <code> M-x compile </code> (the <code> 
M-x </code> should get you to the minibuffer then type 
<code> compile </code>). Now 
type <code> splint test.c </code>.  (you can 
also use the compilation buffer with <code> gcc </code> doing
straight compilation) 

<p>
If you are not using Emacs, your editor may have some similar 
feature to Emacs compilation buffer. Check your edtior documentation.
You can always run Splint from the command line, by using <code>
splint test.c </code>, and the output should scroll on your terminal 
window. (for this approach it would be best if you had a scrolling 
terminal window).

<p>
You should get output like this: 

<code><pre>
<!--#include virtual="Uninitialized.splint"-->
</code></pre>

<p>
(if Splint doesn't work, check the 
installation instructions <A HREF="http://www.splint.org/download.html">
first</A>, and if you are still having trouble e-mail the mailing
list)

<P>
Splint raised a "use before definition" 
warning, and this is what we should expect. We are using 
the variable <code> a </code> before it is defined. Typically in checking
a large source code file you would jump from warning to warning
comparing Splint's output to 
the source code.


<p>
You might
be wondering what an rvalue is. An rvalue is any
expression that can go on the right hand side of an assignment
statement. Numbers  like <code>3</code>, <code>5</code>,
<code>6</code>, are valid rvalues as are variables like <code>
Max</code>, <code>Min</code>, or <code>temp</code>. Lvalues
on the other hand are valid expressions that can go on the left
hand side of an assignment statement. Literal numbers
would not be valid lvalues since you can
not assign a value to a literal number. 

<p>
Other things to be aware of: 

<ul> 
<li>Declarations
can only occur at the start of a program (or 
<i> function </i>). So code like this will not compile: 
<code><pre>
<!--#include virtual="InvalidDeclaration.c"-->
</code></pre>

<li>All variables must be valid C identifiers. The
rules for a variable to be a valid C identifier are the following: 

<ul>
<li>The first character must be a letter. 
<li>Subsequent characters may be either letters, digits, or
underscores.
<li>It must not be a C <A HREF="Keywords.html">keyword.</A>
</ul>

<p>
For a quick exercise determine which identifiers are valid, and which are not.


<ol>
<li><code> 1stPlace       </code>
<li><code> Float          </code>
<li><code> minVertex      </code>
<li><code> register       </code>
<li><code> best-match     </code>
<li><code> __maximum      </code>
<li><code> First&amp;Last </code>
<li><code> FirstBe4LLast  </code>
</ol>
</ul>

<p>
<A HREF="IdentifierQuizAnswers.html"> Check your answers</A>

</ul>
<p>
<h2>Arithmetic Operations</h2>

In C there are five arithmetic operators: <code>+,-,*,/ </code>and the modulus
operator <code>%</code>. Most of the time these will do what you
would expect them to do, but there are some things 
you need to be aware of. 

<ul>
<li>The modulus operator for <code>a % b</code>
returns the remainder when a is divided by b.  e.g. <code>10 % 3</code>
will yield
1 because 10 divided by 3 equals 3 with a remainder of 1.

<br><br>
<li>There is a difference between floating point division and integer
division.  Note that <code> 11 / 2 </code>will not return the floating point
type <code>5.5 </code> but will return the integer type
<code>5</code>. If you want the <code> / </code> operator to instead
performing floating point division then do the following: add a
decimal point to either of the two operands e.g. <code> 11/2.0
</code>. (you can also do this was a <i> cast </i> as we will see in
the example)

<br><br>
<li>If you need to apply the <code> % </code>
operand in cases where the two operands are of different signs the
result will depend on your particular computer. The
rule is that <code> (a / b) * b + a % b </code> Should always equal 
<code>a</code> (as long as <code>b</code> does not equal zero). So in the case we find
<code>-13 % 2</code> is 1 then we know that <code>-13 / 2</code> must 
equal -7.   If -13 % 2 is -1 then we know that -13 / 2 must equal -6.

<br><br>
<li>Precedent of operations is exactly as you would expect from math 
class, that is multiplcation and division come before addition and
subtraction. The expression <code> 3 * 4 + 2 * 7 </code> would be 
parenthesized as <code> (3 * 4) + (2 * 7) </code> not as 
<code> 3 * (4 + 2) * 7 </code>. If you are in doubt 
about the precedence of various operations then you can
always parenthesize the expressions, or look up the 
precedence in this <A
HREF="http://www.eecs.harvard.edu/vino/vino/release-0.40/man/programref/c/operator.html">
table </A> (don't worry if some of these operators look unfamiliar). Looking at this table we can see that multiplication,
division, and modulus all occur before addition, but
you might be curious about what associativity means. All that means 
is that when there is a tie operations will proceed in the order
of associativity. For example:
<pre><code>
3 * 5 % 7 * 2
</pre></code>
will be parenthesized as

<pre><code>
(((3 * 5) % 7) * 2)
</pre></code>
yielding a result of 2. 

Since both the <code> * </code> and <code> % </code> operations
associate
left to right
</ul>
     
Let's look at an example of a common mistake programmers make using the  arithmetic operators, and show how Splint can find
this mistake.

Take a look at the following program:  
<pre><code>  
<!--#include virtual="DivisionMistake.c"-->
</pre></code>

Does this do the right thing? Try it and see, and then scroll down.

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>


You should have got the output <code> 4
</code> instead of the output <code> 4.66667 </code>. This is because, 
as we mentioned above, since both <code>3</code> and <code> a + b + c
</code> are integers the compiler performs integer division 
instead of floating point division, and it truncated the result. This is not the same as rounding. The number
 4.666667 rounded is 5 not 4. The
compiler is saying is that  14 / 3  is equal to 4 with a remainder
of 2. 

What does Splint say about this program? 

<pre><code> 
<!--#include virtual="DivisionMistake.splint"-->
</pre></code>

Splint tells us what we expect. In this line we
assigned an integer type to a floating point variable:
<pre><code>
float avg = (a + b + c) / 3;
</pre></code>

There are two (maybe three) ways to fix this.
One way was alluded to in the
discussion above. Just change the line: 
<pre><code>   
float avg = (a + b + c) / 3;
</pre></code>
to
<pre><code>
float avg = (a + b + c) / 3.0;
</pre></code>

<p>
In this case the compiler performs floating point division because at
least one of the operands is a floating point.

<p>
The other way is with a <i> cast </i>. Technically, a cast is a unary
operator (like the unary -) which converts the operand to a different
type. What is important is that you can use a cast to convert an
operand to a type other than what it actually is for the purposes of a
computation. Consider replacing the above line with: 
<pre><code>
float avg = (a + b + c) / (float) 3;
</pre></code>
or 
<pre><code>
float avg = (float)(a + b + c) / 3.0;
</pre></code>  

In this case, the cast converts its operand to a float, and so
floating point division is done instead of integer division. 
Notice that we didn't have to parenthesize like this: 

<pre><code>
float avg = ((float)(a + b + c)) / 3.0;
</pre></code>  

This is because the cast operator has a higher precedence that the
division operator. Check the <A
HREF="http://www.eecs.harvard.edu/vino/vino/release-0.40/man/programref/c/operator.html">
table </A> to verify this (it is on the second line).

As an exercise, change the code above in whichever of the three
methods
listed you like best, and
note that the program now produces the correct answer, and that Splint
reports no warnings. 



<h2> Logical Operations</h2>

The relational operations are

<code>&lt; &lt;= &gt; &gt;=</code>

These are the familiar, less than, less than or equal, greater than,
and greater than or equal signs. They function just as you would
expect them to when applied to the numeric types <code> int, float
</code>
and <code> double </code>. For example, the expression: <code> 4 > 3
</code>
would yield true while the expression <code> 3 < 1 </code> would yield
false. What are true and false in the C programming language? The rule
is: 

<blockquote>
false is the numeric value zero, and true is any numeric value
other than zero.  
</blockquote>

To test for equality or inequality use
the relational equality or inequality operators,
==, and != respectively. These operators will always return 1 for
a true statement and 0 for a false one. 

Now consider the following operators:

<br><br><br>
<table border>
<caption>Logical Operators</caption>
<th>Operator <th>Name <tr>
<td><code>&&</code>       <td>AND  <tr>
<td><code>||</code>       <td>OR   <tr>
<td><code>! </code>       <td>NOT  
</table>
<br><br><br>


And their respective truth tables:


<br><br><br>
<table border>
<caption>AND Operator</caption>
<th>A        <th>B       <th> A AND B <tr>
<td>True     <td>True    <td> True    <tr>
<td>True     <td>False   <td> False   <tr>
<td>False    <td>True    <td> False   <tr>
<td>False    <td>False   <td> False   
</table>
<br><br><br>

<table border>
<caption>OR Operator</caption>
<th>A        <th>B       <th> A OR B <tr>
<td>True     <td>True    <td> True   <tr>
<td>True     <td>False   <td> True   <tr>
<td>False    <td>True    <td> True   <tr>
<td>False    <td>False   <td> False   
</table>

<br><br><br>
<table border>
<caption>NOT Operator</caption>
<th>A        <th>NOT A <tr>   
<td>True     <td>False <tr>  
<td>False    <td>True 
</table>
<br><br><br>

A good way to get familiar with the logical, relational, and
arithmetic operators is to just "play" with them. Write 
some simple code, and see what it evaluates to. Try a few of the following
exercises before moving on (keeping in mind that 1 is true, and 0
is false). 

<ol>
<li> Given that:
     <pre><code> int a = 0; </pre></code>
     <pre><code> int b = 1; </pre></code>
     <pre><code> int c = 1; </pre></code>
     Evaluate:
     <pre><code> (a && b) || c </pre></code>

<li> Given that:
     <pre><code> int a = 35; </pre></code>
     <pre><code> int b = -4; </pre></code>
     <pre><code> int c = 0; </pre></code>
     <pre><code> int d = 5; </pre></code>
     Evaluate:
     <pre><code> ((b < a) && c) || d</pre></code>

<li> Given that:
     <pre><code> int a = -35; </pre></code>
     <pre><code> int b = -4;  </pre></code>
     <pre><code> int c = 0;   </pre></code>
     <pre><code> int d = 5;   </pre></code>
     Evaluate: (in precedence what comes first && or ||?) 
     <pre><code> (b < a) && c || d</pre></code>


<li> Given that:
     <pre><code> int a = -35; </pre></code>
     <pre><code> int b = -4;  </pre></code>
     <pre><code> int c = 0;   </pre></code>
     <pre><code> int d = 5;   </pre></code>
     Evaluate:
     <pre><code> (b < a) < c < d </pre></code>


<li> Given that:
     <pre><code> int a = 14; </pre></code>
     <pre><code> int b = -1; </pre></code>
     <pre><code> int c = 1;  </pre></code>
     <pre><code> int d = 3;  </pre></code>
     Evaluate:
     <pre><code> ((-b == c) >= d + 13) + 13 >= a </pre></code>
</ol>

<A HREF="LogicalQuizAnswers.html">Check your answers </A>

<h2>Characters and Strings</h2>
<p>
The <code> char </code> type represents a character.  The <A
HREF="http://www.robelle.com/library/smugbook/ascii.html"> ASCII
Character Set </A> defines 128 different characters, of which 96 
are printing character and the other 32 are control characters.
(note that 128 is 2<sup>7</sup>).

<p>
Here is how to declare a character:

<code><pre>
char OurCharacter = 'b';
</code></pre>

<p>
The following code woud print out the character:

<code><pre>
<!--#include virtual="PrintCharacter.c"-->
</code></pre>


<p>
Here is how to define and print out a string variable:
<code><pre>
<!--#include virtual="PrintString.c"-->
</code></pre> 

<p>
Notice that single quotes specify a character value, and
double quotes specify a string of zero or more characters.

<p>
The character array <code>TestString</code>
is 12 bytes long rather than
11 because an extra character is used at the end
for the NULL character ('\0') to specify
the end of the string. As an exercise try changing
the above 12 to an 11, and then run Splint on the code,
and see what the output is.

<p>
You can include a quotes in the string
by backslashing them: 

<code><pre>
<!--#include virtual="PrintQuotedString.c"-->
</code></pre>

<p>
This will print out:

<code><pre>
My favorite poem is "The Raven" by Edgar Allen Poe
</code></pre>

<p>
Here are some character constants you can play with: 
<br><br>
<table border>
<caption></caption>
<th>Character Name        <th>ASCII Name       <th>Escape Sequence <tr>
<td>newline                 <td>NL            <td>\n   <tr>
<td>horizontal tab          <td>HT            <td>\t   <tr>
<td>vertical tab            <td>VT            <td>\v   <tr>
<td>backspace               <td>BS            <td>\b   <tr>
<td>form feed               <td>FF            <td>\f   <tr>
<td>alert or bell           <td>BEL           <td>\a   <tr>
<td>carriage return         <td>CR            <td>\r   <tr>
<td>blackslash              <td>\             <td>\\   <tr>
<td>single quote            <td>'             <td>\'   <tr>
<td>dobule quote            <td>""             <td>\"   <tr>
<td>question mark           <td>?             <td>\?   <tr>
</table>
<br>

<p>
Try and write a program which rings the bell on the computer
(character constant \a).

<p>
The next chapter focuses on flow control. 

<p>
<A HREF="../chapter3/chapter3.php"> Next </A>
<p>
<A HREF="../index.html"> Contents </A>
</body>
</html>















