#include <stdio.h>

int read_integer(void);

int main(void) {
  int running_sum = 0, read_int = 0, i = 0;
  printf("Enter positive numbers or a negative number to stop (int):\n");
  do {
    read_int = read_integer();
    if (read_int >= 0) {
      i++;
      running_sum += read_int;
    } 
  } while (read_int >= 0);
  printf("Sum of your nums: %d\n"
         "Total amount of numbers: %d\n"
         "Average: %.3f\n", running_sum, i, (float) running_sum / i);

  return 0;
}

