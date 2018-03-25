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
      printf("Number %d is prime\n", Number);   
    case 1:
    case 9:
      printf("Number %d is odd\n", Number); 
      break;
    case 0:
    case 2:
    case 4:
    case 6:
    case 8:
      printf("Number %d is even\n", Number);
      break;
    default:
      printf("Number entered is not between 0 and 9 inclusive\n");
    }

  return 0;
}

