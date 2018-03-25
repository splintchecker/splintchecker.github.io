#include "stdlib.h"
int main()
{
  int i;
  int n = 10; /*pick n = 10*/
  int sum = 0;
  for(i = 1; i <= n; i++)
  {
    sum = sum + i;
  }
  printf("The sum from 1 to %d is %d", n, sum);
  return 0;
}
