#include <stdio.h>
/*Maybe I should just return a boolean value based on if the
 * input value is actually int or not. The repeating loop could be
 * handled outside of this function. If we just returned true or
 * false (and stored the actual input to pointer's location?) we
 * could have vastly different usecases for this*/
int read_integer(void) {
  int input = 0, result = 0;

  while (!result) {
    result = scanf("%d", &input);
    if (!result) {
      printf("Invalid input! Enter an number:\n");
    }
    while (getchar() != '\n') {
    }
  }
  return input;
}
