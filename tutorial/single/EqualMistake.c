#include "stdlib.h"


int main()
{
  int AccountValue = 1000;
  int Delta;

  printf("I have $%d in my account.\n", AccountValue);
  Delta = 500; AccountValue = AccountValue - Delta;
  printf("I withdrew $%d from my account and now have $%d in my account.\n", Delta, AccountValue);
  Delta = 150; AccountValue = AccountValue + Delta;
  printf("I deposited $%d into my account and now have $%d in my account.\n", Delta, AccountValue);
  Delta = 650; AccountValue = AccountValue - Delta;
  printf("I withdrew $%d into my account and now have $%d in my account.\n", Delta, AccountValue);
   
  if (AccountValue = 0)
   { 
    printf("I have $%d in my account. I'm broke!", AccountValue);
   }
   else
     {
       printf("I have $%d in my account, so I'm not broke", AccountValue);
     }
   
   return 0;
}
