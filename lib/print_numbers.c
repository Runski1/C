#include <stdio.h>
#define MIN_INT 0x80000000
#define MAX_INT 0x7FFFFFFF
#define ARRAY_LENGTH 15

int random_in_range(int min, int max);

void print_numbers(const int *array, int count) {
  for (int i=0; i<count;i++) {
    printf("%8d\n", array[i]);
  }
}

int main(void) {
  int random_int_array[ARRAY_LENGTH];
  for (int i = 0; i<ARRAY_LENGTH; i++) {
    random_int_array[i] = random_in_range(MIN_INT, MAX_INT);
  }
  return 0;
}

