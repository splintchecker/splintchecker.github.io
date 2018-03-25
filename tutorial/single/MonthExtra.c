#include "stdlib.h"

int main()
{
  int Month;
  int Year;
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
        printf("Enter a year: "); scanf("%d", &Year);
	if (  ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0))
	{
	  printf("The month you picked has 29 days");  
	}
	else
	{
	  printf("The month you picked has 28 days");
	}
	break;
      default:
        printf("Error: Month must be a number from 1 to 12 inclusive");
    }

    return 0;
}


