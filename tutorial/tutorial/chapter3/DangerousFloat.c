#include "stdlib.h"

int main()
{
  float f = 3.0;
  float Delta = 1e-1000;
  float Number = f;
  float NumberPlusDelta = f + Delta;

  if (Number == NumberPlusDelta)
    {
      printf("How canst that which is not the same be the same?\n");
    }
  return 0;

}
