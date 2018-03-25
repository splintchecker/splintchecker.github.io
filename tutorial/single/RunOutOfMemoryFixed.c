#include "stdlib.h"

typedef struct ba
{
  char big[1048576];
} BigArray;


int main()
{
  BigArray* p; int i = 1;
  p = malloc(sizeof(*p));
  while (p != NULL)
    {
      free(p);
      printf("Just allocated %d\n", i);
      p = malloc(sizeof(*p));
      i++;
    }
  printf("The computer actually ran out of memory!!\n");
  printf("Malloc returned NULL\n");
  return 0;
}
