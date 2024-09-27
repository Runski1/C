#include "../lib/read_input.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 80
#define MAX_LINES 100

int main(void) {
  FILE *text_file = NULL;
  char lines[MAX_LINES][LINE_LENGTH] = {'\0'};
  int linecount = 0;
  char filename[30] = {'\0'};
  printf("Enter a filename:\n> ");
  if (read_string(filename, sizeof(filename), stdin) != 0) {
    perror("Bad filename");
    return EXIT_FAILURE;
  }
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
    if (read_ret_val == 0) {// If line read is successful and line not too long
      linecount++;
    } else if (read_ret_val == 1) {
      /* If line is too long or fgets returns null pointer for some other reason
       * Just reads more lines and doesn't increase linecount.
       * Effectively deletes the whole line if it is too long.
       * */
      while (read_string(lines[linecount], LINE_LENGTH, text_file) == 1){};
    }
  }
  if (errno) {
    perror(filename);
  }
  fclose(text_file);
  text_file = fopen("output.txt", "w");
  int write_ret_val = 0;
  linecount = 0;
    for (int i = 0; i < MAX_LINES; i++) {
    if (*lines[i] != '\0') {linecount++;}
    write_ret_val = fputs(lines[i], text_file);
    fputs("\n", text_file);
  }
  if (write_ret_val == EOF) {
    perror("fputs()");
  }
  printf("Lines: %d\n", linecount);
  if (read_ret_val == -1) {
    printf("EOF reached\n");
  }
  return 0;
}
