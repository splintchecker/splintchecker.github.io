#include <stdlib.h>

int main()
{
  int i = 1;
  int n = 10; /*let's pick 10 for this example*/
  for(i = 1; i <= n; i++)
    {
      printf("%d\t%d", i, i * i * i);
      printf("\n");
    }
  return 0;

}
