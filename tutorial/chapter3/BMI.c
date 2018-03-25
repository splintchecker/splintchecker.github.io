#include "stdlib.h"

/* 2.2. kg for every lb */ 
#define KG_PER_LB 2.2
/* 39.37 in for every m */ 
#define IN_PER_M 39.37

int main()
{
  float Weight;
  float Height;
  float BMI;

  printf("Enter weight (lbs.): "); (void) scanf("%g", &Weight); 
  printf("Enter height (in.): ");  (void) scanf("%g", &Height);

  BMI =    (Weight/KG_PER_LB)  / ((Height * Height)/(IN_PER_M * IN_PER_M));

  printf("Your body mass index is %g\n", BMI);

  if ( BMI >= 30)
    {
      printf("Well above average Body Mass Index\n");
    }
  else if ( 25 <= BMI && BMI < 30)
    {
      printf("Above average Body Mass Index\n");
    }
  else if ( 19 <= BMI && BMI < 25)
    {
      printf("Average Body Mass Index\n");
    }
  else if ( 0 <= BMI && BMI < 19)
    {
      printf("Below average Body Mass Index\n");
    }

  return 0;

}
