#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 20

int random_int_in_range(int min, int max);
bool read_uint(unsigned int *value);

int find_first(const unsigned int *array, unsigned int what) {
  int num = -1;
  int i = 0;
  do {
    if (array[i] == what) {
      return i;
    }
    i++;
  } while (array[i] != 0);
  return num;
}

int main(void) {

  // variable init
  bool isnum = false;
  unsigned int number_to_find = 0;
  int found_num = -1;
  srand(time(NULL));
  unsigned int num_array[ARRAY_SIZE];
  num_array[ARRAY_SIZE - 1] = 0;

  /* initialize num_array and print on screen */
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    num_array[i] = (unsigned int)random_int_in_range(1, 20);
    printf("%d\n", num_array[i]);
  }
  printf("%d\n", num_array[ARRAY_SIZE - 1]);

// Main loop
  do {
    printf("Enter a positive number to search for (0 to stop)\n");
    while (!isnum) {
      isnum = read_uint(&number_to_find);
      if (!isnum) {
        printf("\nIncorrect input.\n");
      }
    }
    found_num = find_first(num_array, number_to_find);
    if (number_to_find !=
        0) { // this if wrap is to prevent Not found to be printed on exit
      if (found_num == -1) {
        printf("Not found\n");
      } else {
        printf("Found your number at index %d\n", found_num);
      }
      isnum = false;
    }
  } while (number_to_find != 0);

  return 0;
}
