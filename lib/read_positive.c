#include <stdbool.h>
#include <stdio.h>
#define INT_MAX 0x7FFFFFFF // max signed int32
#define MAX_INT32_CHARS 12 // 10c + \0 + \n

void clear_input_buffer(void);
bool read_string(char *str, int max_strlen);

bool read_positive(int *value) {
  /* I don't get why won't we just use unsigned int instead */
  char input_str[MAX_INT32_CHARS] = "\0";
  long int number = -1;
  printf("Enter a positive number: ");

  if (read_string(input_str, MAX_INT32_CHARS)) {
    sscanf(input_str, "%ld", &number);
  }

  if (number > 0 && number <= INT_MAX) {
    *value = (int)number;
    return true;
  } else {
    number = -1;
    return false;
  }
}
