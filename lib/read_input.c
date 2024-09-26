#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

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

int read_string(char *str, int len);

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
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

int read_string(char *str, int max_strlen) {
  char *nullfinder;
  nullfinder = fgets(str, max_strlen, stdin);
  if (nullfinder == NULL || strchr(str, '\n') == NULL) {
    if (feof(stdin)) {
      clearerr(stdin);
      return -1;
    }
    clear_input_buffer();
    return 1;
  } else {
    char *newline = strchr(str, '\n');
    *newline = '\0';
    return 0;
  }
}

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
