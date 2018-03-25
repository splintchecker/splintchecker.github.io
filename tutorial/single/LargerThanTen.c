#include "stdlib.h"
int main()
{
  int array[10] = {5, 8, 9, 23, 17, 4, 7, 10, 3, 8};
  int i;
  for(i = 0; i <= 9; i++)  /* in C arrays are indexed starting at 0 */
    {
      if (array[i] > 10)
	{
	  printf("We found a number larger than 10!\n");
	  printf("At the %d position and it is %d", i, array[i]);
	  break;
	}
    }
      

  return 0;
}
