#include "stdlib.h"

typedef struct ba
{
  char big[1000000];
} BigArray;


int main()
{
  BigArray* p; int i = 1;
  p = malloc(sizeof(*p));
  while (p != NULL)
    {
      printf("Just allocated %d\n", i);
      p = malloc(sizeof(*p));
      i++;
    }
  printf("The computer ran out of memory.\n");
  printf("Malloc returned NULL\n");
  return 0;
}



