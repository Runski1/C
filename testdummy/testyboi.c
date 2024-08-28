#include <stdio.h>

void clear_input_buffer(void) {
  while (getchar() != '\n') {
  }
}

int main(void) {
  int result = 0;
  int integer = 0;
  while (1) {
    printf("enter integer: ");
    result = scanf("%d", &integer);
    printf("result: %d\n", result);
    if (result == 1) {
      clear_input_buffer();
      printf("printing captured int: %d\n", integer);
      break;
    } else {
      clear_input_buffer();
    }

    printf("%d bad result. \n", result);
  }
  return 0;
}
