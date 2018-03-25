#include "stdlib.h"

int main()
{
  char c = 'b';

  switch(c)
    {
      case 'A': case 'a':
	printf("You got an A! Congratulations\n");
      case 'B': case 'b':
	printf("You got a B. Good Job\n");
      case 'C': case 'c':
	printf("C is average\n");
      case 'D': case 'd':
	printf("A D is unsatisfactory. Learn the material and try harder next time!\n");
      case 'F':  case 'f':
       printf("You get an F! Oh no! Try harder next time and don't get discouraged!\n");
      default:
	printf("You entered: %c. I don't know what this means", c);
    }

  return 0;
}
