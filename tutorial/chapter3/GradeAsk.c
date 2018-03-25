#include "stdlib.h"

int main()
{
  char c;
  printf("Enter your grade for your last test: "); scanf("%c", &c);

  if (c == 'A')
    {
      printf("You got an A! Congratulations\n");
    }
  else if (c == 'B')
    {
      printf("You got a B. Good Job\n");
    }
  else if (c == 'C')
    {
      printf("C is average\n");
    }
  else if (c == 'D')
    {
      printf("D is unsatisfactory. Learn the material and try harder next time!\n");
    }
  else if ( c == 'F')
    {
      printf("You got an F. Try harder next time and don't get discouraged.\n");
    }
  else
    {
      printf("You entered: %c. I don't know what this means", c);
    }

  return 0;
}
