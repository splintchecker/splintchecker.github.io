#include "stdlib.h"

int main()
{
  int Number;
  int Factorial; 
  int i;
  printf("Enter a number greater than or equal to 1: ");
 
  (void) scanf("%d",  &Number);
  
  Factorial = 1;
  for(i = 1; i <= Number; i++)
    {
      Factorial *= i;
    }
  printf("%d! = %d", Number, Factorial);

  return 0;
  
}
