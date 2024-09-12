#include <stdio.h>

int read_integer(void);

int read_range(int low, int high) {
  int chosen_num = low - 1;
  do {
    while (low > chosen_num || high < chosen_num) {
      printf("Enter a number between %d and %d.\n", low, high);
      chosen_num = read_integer();
    }
  } while (chosen_num < low || chosen_num > high);
  return chosen_num;
}
