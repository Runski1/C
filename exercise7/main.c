#include <stdbool.h>
#include <stdio.h>

bool read_positive(int *value);

/*TLDR IS:
 * use fgets instead of gets. Syntax:
 * fgets(arraypointer, 5, stdin); This will get total of 4 characters
 * from stdin and store to arraypointer. Alloc memory for arraypointer
 * as needed. 4 vs 5> because of \0 escape char that is needed for
 * strings */
int main(void) {
  int input;
  bool is_num = false;
  printf("Guess how much money I have!\n");
  int i = 0;
  do {
    is_num = read_positive(&input);
    if (!is_num) {
      i++;
      printf("Incorrect input.\n");
    } else {
      printf("You didn't get it right. I have %lld euros.\n",2 * (long long int) input + 20);
    }
  } while (i < 3);
  printf("I give up! See you later!\n"); 
  return 0;
}
