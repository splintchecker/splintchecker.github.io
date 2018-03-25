#include "stdlib.h"

int main()
{
  int Number;  int CurrentDigit;
  printf("Enter an integer greater than or equal to 1: ");
  scanf("%d", &Number);
  while (Number > 0)
    {
      CurrentDigit = Number % 2;
      printf("%d", CurrentDigit);
      Number = Number / 2;
    }
  return 0;

}
