#include <stdio.h>

int read_integer(void);
int read_range(int low, int high);

int main(void) {
  int chosen_num = 0;
  printf("Let's play!\nRoll a die and enter your result.\n");
  for (int i = 0; i < 3; i++) {
    chosen_num = read_range(1, 6);
    if (chosen_num < 6) {
      printf("I got a %d. I win!\n", chosen_num + 1);
    } else {
      printf("I got a 6. It is a tie!\n");
    }
  }
  printf("Better luck next time! Bye!\n");
  return 0;
}
