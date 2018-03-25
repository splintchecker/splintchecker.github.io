#include "stdlib.h"

int main()
{
  char c;
  printf("Enter your grade for your last test: "); scanf("%c", &c);

  switch(c)
    {
      case 'A':
	printf("You got an A! Congratulations\n");
	break;
      case 'B':
	printf("You got a B. Good Job\n");
	break;
      case 'C':
	printf("C is average.\n");
	break;
      case 'D':
	printf("A D is unsatisfactory. Learn the material and try harder next time!\n");
	break;
      case 'F': 
       printf("You got an F. Try harder next time and don't get discouraged!\n");
       break;
      default:
	printf("You entered: %c. I don't know what this means", c);
	break;
    }

  return 0;
}
