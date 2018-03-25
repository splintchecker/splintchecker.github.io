#include "stdlib.h"
int main()
{
  int* ip = (int*)malloc(5 * sizeof(int));
  if(ip == NULL) {exit(EXIT_FAILURE);} /* no more space left in the heap */
  ip[0] = 3;
  free(ip);
  ip[3] = 1;
  return 0;
}
