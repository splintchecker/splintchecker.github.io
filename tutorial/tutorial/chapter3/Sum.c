#include "stdlib.h"
int main()
{
  int i = 1;
  int n = 10; /*pick n = 10*/
  int sum = 0;
  while (i <= n)
  {
    sum = sum + i; 
    i++;
  }
  printf("The sum from 1 to %d is %d", n, sum);
  return 0;
}
