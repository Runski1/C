#include <stdbool.h>
#include <stdio.h>
#define MAX_INT32_CHARS 12 // 10c + \0 + \n

void clear_input_buffer(void);

bool read_string(char *str, int max_strlen);

bool read_uint(unsigned int *value) {
  char input_str[MAX_INT32_CHARS] = "\0";
  long long int number = -1;

  if (read_string(input_str, MAX_INT32_CHARS)) {
    sscanf(input_str, "%lld", &number);
  }

  if (number >= 0 && number <= 0xFFFFFFFF) {
    *value = number;
    return true;
  } else {
    number = -1;
    return false;
  }
}
