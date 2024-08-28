#include <stdio.h>

/* I tried if I could generate random numbers just by not assigning a value for num
 * but it looks like there is a random value assigned for num only once, I guess
 * when it's defined OR when it's accessed the first time*/
int main(void)
{
  int num;
  int nums[500];
  int min= 0x0FFFFFFF;
  int max=0x0;
  for (int i=0; i < sizeof(nums)/sizeof(nums[0]); i++)
  {
    nums[i] = num;
    printf("filling array %d\n", i);
  }
  for (int i=0; i < sizeof(nums)/sizeof(nums[0]); i++)
  {
    if (nums[i] < min)
    {
      min = nums[i];
    }
    if (nums[i] > max)
    {
      max = nums[i];
    }
    printf("Int: %d,    %d\n",nums[i], i);
  }
  printf("min: %d    max: %d\n", min, max);
  return 0;
  }
