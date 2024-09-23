#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINESIZE 80 // 12 for negative int + \n\0
#define NAME_LEN 30

/* I need to do something with my read_integer. Maybe read lld?
 * What I think happens here is that ln34 or 35 reads the int only partially
 * and causes weird numbers being stored to min and max variables.
 */
int read_string(char *str, int max_strlen);

/*
#include <errno.h>
#include <stdio.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");

    if (file == NULL) {
        // Custom formatted error message
        char errmsg[100];
        snprintf(errmsg, sizeof(errmsg), "Failed to open '%s'",
"non_existent_file.txt"); perror(errmsg);
    }

    return 0;
}
*/
int main(void) {
  FILE *my_file;
  char str[LINESIZE]; // \0 and \n
  int linecount = 0;
  long int min = LONG_MAX;
  long int max = LONG_MIN;
  int num = 0;
  char filename[NAME_LEN] = {'\0'};
  char err_msg[LINESIZE] = {'\0'};
  errno = 0; // just in case errno has been already set

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
  while (!feof(my_file) && errno == 0) {
    if (fgets(str, LINESIZE, my_file) != NULL) {
      num = strtol(str, NULL, 0);
      if (num > max) {
        max = num;
      }
      if (num < min) {
        min = num;
      }
      linecount++;
    }
  }
  printf("Numbers read: %d\n", linecount);
  printf("Min: %ld\nMax: %ld\n", min, max);
  if (!feof(my_file)) {
    snprintf(err_msg, sizeof(err_msg), "%s - Line %d", filename, linecount);
    perror(err_msg);
    fclose(my_file);
    return EXIT_FAILURE;
  }
  fclose(my_file);
  return EXIT_SUCCESS;
}
