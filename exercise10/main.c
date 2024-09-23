#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_STRLEN 0xFFF

int read_string(char *str, int max_strlen);

int main(void) {
  char string[MAX_STRLEN] = {'\0'};
  int result = 0;
  do {
    printf("Input a string, or \"stop\" to quit the program.\n> ");

    result = read_string(string, MAX_STRLEN);
    if (result == -1) {
      printf("Program stopped. (exit code %d)\n", result);
      return -1;
    } else if (result == 1) {
      printf("String is too long or an error occured.\n");
    } else {
      size_t string_length = strlen(string);
      /* I have since modified read_string to remove the \n
      if (string_length > 0 && string[string_length - 1] == '\n') {
        string[string_length - 1] = '\0';
      } */
      printf("Your string is %d characters long.\n", (int)string_length);
    }
  } while (strcmp(string, "stop") != 0);
  return 0;
}
