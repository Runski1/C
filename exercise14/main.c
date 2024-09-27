#include "../lib/read_input.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 80
#define MAX_LINES 100

char *string_to_ucase(char *str) {
  int i = 0;
  char c = str[i];
  while (str[i]) {
    c = toupper(str[i]);
    str[i] = c;
    i++;
  }
  return str;
}

int main(void) {
  FILE *text_file = NULL;
  char lines[MAX_LINES][LINE_LENGTH] = {'\0'};
  int linecount = 0;
  char filename[30] = {'\0'};
  printf("Enter name of source file:\n> ");
  read_string(filename, sizeof(filename), stdin);
  text_file = fopen(filename, "r");
  if (text_file == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }
  errno = 0;

  /* I'm not totally sure how this should work when a line longer than
   * LINE_LENTGH is read from the file. I'll dump it I guess
   * */
  int read_ret_val = 0;
  while (linecount < MAX_LINES && read_ret_val >= 0) { // EOF sets ret_val to -1
    read_ret_val = read_string(lines[linecount], LINE_LENGTH, text_file);
    if (read_ret_val == 0) { // If line read is successful and line not too long
      linecount++;
    } else if (read_ret_val == 1) {
      /* If line is too long or fgets returns null pointer for some other reason
       * Just reads more lines and doesn't increase linecount.
       * Effectively deletes the whole line if it is too long.
       * */
      while (read_string(lines[linecount], LINE_LENGTH, text_file) == 1) {
      };
    }
  }
  if (errno) {
    perror(filename);
  }
  fclose(text_file);
  do {
    printf("Enter name of target file:\n> ");
  } while (read_string(filename, sizeof(filename), stdin) != 0);
  text_file = fopen(filename, "w");
  int write_ret_val = 0;
  linecount = 0;
  for (int i = 0; i < MAX_LINES; i++) {
    if (*lines[i] != '\0') {
      write_ret_val = fputs(string_to_ucase(lines[i]), text_file);
      fputs("\n", text_file);
      linecount++;
    }
  }
  if (write_ret_val == EOF) {
    perror("fputs()");
  }
  if (read_ret_val == -1) {
    printf("EOF reached\n");
  }
  printf("Lines written in %s: %d\n", filename, linecount);
  return 0;
}
