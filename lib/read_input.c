#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_INT32_CHARS 12 // 10c + \0 + \n

void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
}


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

int read_string(char *str, int len, FILE *stream);

bool read_positive(int *value) {
  /* I don't get why won't we just use unsigned int instead */
  char input_str[MAX_INT32_CHARS] = "\0";
  long int number = -1;
  printf("Enter a positive number: ");

  if (read_string(input_str, MAX_INT32_CHARS, stdin)) {
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

int read_range(int low, int high) {
  int chosen_num = low - 1;
  do {
    while (low > chosen_num || high < chosen_num) {
      printf("Enter a number between %d and %d.\n", low, high);
      chosen_num = read_integer();
    }
  } while (chosen_num < low || chosen_num > high);
  return chosen_num;
}

int read_string(char *str, int max_strlen, FILE *stream) {
  char *nullfinder;
  nullfinder = fgets(str, max_strlen, stream);
  if (nullfinder == NULL || strchr(str, '\n') == NULL) {
    if (feof(stream)) {
      clearerr(stream);
      return -1; // EOF
    }
    // clear_input_buffer(); This has been a pain in the ass for me :(
    return 1; // Invalid input, in most cases too long string
  } else {
    char *newline = strchr(str, '\n');
    *newline = '\0';
    return 0; // success
  }
}

bool read_uint(unsigned int *value) {
  char input_str[MAX_INT32_CHARS] = "\0";
  long long int number = -1;

  if (read_string(input_str, MAX_INT32_CHARS, stdin)) {
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
