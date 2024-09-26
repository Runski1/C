#include "../lib/read_input.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 30

int main(void) {
  FILE *my_file;
  int num_count = 0;
  long int num = 0;
  long int min = LONG_MAX;
  long int max = LONG_MIN;
  char filename[NAME_LEN] = {'\0'};

  printf("Open a file\n>./");
  if (read_string(filename, NAME_LEN)) {
    printf("\nBad filename. Program exits.\n");
    return EXIT_FAILURE;
  }
  my_file = fopen(filename, "r");
  if (my_file == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  } else {
    printf("File was opened.\n");
  }
  while (fscanf(my_file, "%ld", &num) == 1) {
    min = (num < min) ? num : min;
    max = (num > max) ? num : max;
    num_count++;
  }
  fclose(my_file);
  if (num_count > 0) {
    printf("%30s%ld\n", "Smallest number: ", min);
    printf("%30s%ld\n", "Biggest number: ", max);
    printf("%30s%d\n", "Total amount of numbers read: ", num_count);
    if (min == LONG_MIN || max == LONG_MAX)
      printf("WARNING: Integer overflow might have happened.\n");

    return EXIT_SUCCESS;
  } else {
    printf("No numbers were read.\n");
    return EXIT_FAILURE;
  }
}
