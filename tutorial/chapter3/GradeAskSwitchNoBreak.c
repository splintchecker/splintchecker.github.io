#include "stdlib.h"

int main()
{
  char c = 'B';

  switch(c)
    {
      case 'A': 
	printf("You got an A! Congratulations\n");
      case 'B': 
	printf("You got a B. Good Job\n");
      case 'C': 
	printf("C is average\n");
      case 'D':
	printf("A D is unsatisfactory. Learn the material and try harder next time!\n");
      case 'F': 
       printf("You got an F. Try harder next time and don't get discouraged!\n");
      default:
	printf("You entered: %c. I don't know what this means", c);
    }

  return 0;
}
