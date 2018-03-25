#include "stdlib.h"

int main()
{
  int Number;
  
  printf("Enter a number (0-9): ");  scanf("%d", &Number);

  switch(Number)
    {
    case 3:
    case 5:
    case 7:
      printf("Digit is prime\n");  /*@fallthrough@*/  
    case 1:
    case 9:
      printf("Digit is odd\n"); 
      break;
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
      printf("Digit is even\n");
      break;
    default:
      printf("Number entered is not between 0 and 9 inclusive\n");
    }

  return 0;
}

