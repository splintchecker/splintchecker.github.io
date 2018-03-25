static int* global;

static void PrintValue(int* guy)
{
  printf("The value of the integer pointer is %d", *guy); 

}

static void f()
{
  int i = 3;
  global = &i;
}


int main()
{
  printf("Value of global before: %p\n", global);
  f();
  printf("Value of global after:  %p\n", global);
  PrintValue(global);
  return 0;

}


