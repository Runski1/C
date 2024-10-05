#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/* If you name your file longer than 30 characters
 * you are an idiot who deserves to be burned at the stake
 */
#define FILENAME_LEN 30

#define MAX_INT32_CHARS 12 // 10c + \0 + \n

void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int read_integer(void) {
  long long int input = 0;
  int result = 0;

  while (!result) {
    result = scanf("%lld", &input);
    if (!result) {
      printf("Invalid input! Enter a valid number:\n");
    } else if (input < INT_MIN || input > INT_MAX) {
      printf("Number out of range! Enter a number between %d and %d.\n", INT_MIN, INT_MAX);
      result = 0;
    }
    while (getchar() != '\n') {
    }
  }
  return (int) input;
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

  if (number >= 0 && number <= INT_MAX) {
    *value = (int)number;
    return true;
  } else {
    number = -1;
    return false;
  }
}

int read_range(int low, int high, char *str) {
  int chosen_num = low - 1;
  while (low > chosen_num || high < chosen_num) {
    printf("%s", str);
    chosen_num = read_integer();
  }
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
    /* This is hacky way of doing things, but only way I can think of 
     * to prevent too long user inputs to flooding into later fgets calls that 
     * read from stdin.
     * */
    if (stream == stdin) {
      clear_input_buffer();
    }
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

/* Returns pointer to FILE on success, null pointer on failure 
 * modes: "r", "w" ... for fopen
 * */
FILE * open_file(char* filename, const int filename_len, char *mode) {
  FILE *file = NULL;
  printf("Enter filename:\n> ");
  if (read_string(filename, filename_len, stdin) != 0) {
    printf("Bad filename.\n");
    return NULL;
  }
  file = fopen(filename, mode);
  return file;
}
