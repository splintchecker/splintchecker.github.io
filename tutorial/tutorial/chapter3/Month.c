#include "stdlib.h"

int main()
{
  int Month;
  printf("Enter a month number: ");  scanf("%d", &Month);

  switch (Month)
    {  
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
	printf("The month you picked has 31 days");
        break;
      case 4:
      case 6:
      case 9:
      case 11:
	printf("The month you picked has 30 days.");
         break;
      case 2:
        printf("The month you picked has either 28 or 29 days");  
	break;
      default:
        printf("Error: Month must be a number from 1 to 12 inclusive");
    }

    return 0;
}
