int main()
{
  void* ip; void *ig; 
  ip = (void *) malloc(5);
  ig = (void*)0x11112222;
  ip = ig;
  return 0;

}
 
