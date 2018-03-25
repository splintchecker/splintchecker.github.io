#include "stdlib.h"

int main()
{
  int array[10] = {5, 8, 24, 7, 18, 3, 1, 2, 25, 14};
  int i;
  int max = -999;
  for(i = 0; i <= 9; i++)
    {
      if (array[i] > max)
	{
	  max == array[i];
	}
    }
  
  printf("The maximum element in the array is %d", max);

  return 0;

}
     
