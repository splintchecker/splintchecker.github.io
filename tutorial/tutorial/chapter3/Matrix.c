#include "stdlib.h"
int main()
{
  int matrix[3][3] = {{3, 4, 9}, {5, 17, 0}, {9, 8, 21}};
  int i; int j;

  for(i = 0; i <= 2; i++)
    {
      for(j = 0; j <= 2; j++)
	{
	  if (matrix[i][j] > 10)
	    {
	      printf("We found a number larger than 10!\n");
	      printf("matrix[%d][%d] is %d\n", i, j, matrix[i][j]);
	      break;
	    }
	}
    }
  return 0;

}
