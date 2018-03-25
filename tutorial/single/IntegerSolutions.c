#include "stdlib.h"

int main()
{
  int a;
  int b;
  int c;
  int d;

  for(a = 1; a <= 14; a++)
    {
      for(b = a; b <= 14; b++)
	{
	  for (c = b; c <= 14; c++)
	    {
	      for(d = c; d <= 14; d++)
		{
		  if (a * a + b * b + c * c + d * d == 200)
		    {
		      printf("We have a solution!\n");
		      printf("%d^2 + %d^2 + %d^2 + %d^2 = 200\n", a, b, c, d);
		    }
		}
	    }
	}
    }

  return 0;

}
