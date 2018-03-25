#include "stdlib.h"
int main()
{
  int i = 1;
  int n = 10; /* let's pick n = 10 arbitrarily */
  int sum = 0;
  while (i <= n)
  {
    sum = sum + i;
    
  }
  printf("The sum from 1 to %d is %d", n, sum);
  return 0;
}
