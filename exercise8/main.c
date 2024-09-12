#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MIN_INT -9999999 // Had to keep these within 8 characters
#define MAX_INT 99999999
#define ARRAY_LENGTH 15

int random_int_in_range(int min, int max);

void print_numbers(const int *array, int count) {
  for (int i=0; i<count;i++) {
    printf("%8d\n", array[i]);
  }
}

int main(void) {
  srand(time(NULL)); // seed the rand() only once
  int random_int_array[ARRAY_LENGTH];
  for (int i = 0; i<ARRAY_LENGTH; i++) {
    random_int_array[i] = random_int_in_range(MIN_INT, MAX_INT);
  }
  print_numbers(random_int_array, ARRAY_LENGTH);
  return 0;
}

