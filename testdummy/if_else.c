#include <stdio.h>

/* I tried if I could generate random numbers just by not assigning a value for num
 * but it looks like there is a random value assigned for num only once, I guess
 * when it's defined OR when it's accessed the first time*/
int main(void)
{
  int a = 2;
  if (a == 1)
  {
    printf("Hello from if!\n");
  } else if (a == 2)
  {
    printf("Hello from else!\n");
  }

  int b = 2, c=0;
  if (b ==2)
  {
    printf("Hello from b if!\n");
  }else while (c < 3)
  {
    printf("Hello from B while!\n");
    c++;
  }
  return 0;
}
