#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LINESIZE 14 // 12 for negative int + \n\0
#define FILENAME_LEN 30

/* I need to do something with my read_integer. Maybe read lld?
 * What I think happens here is that ln34 or 35 reads the int only partially
 * and causes weird numbers being stored to min and max variables.
 */
int read_string(char *str, int max_strlen);

int main(void) {
  FILE *my_file;
  char str[LINESIZE]; // \0 and \n
  int linecount = 0;
  int min = INT_MAX;
  int max = INT_MIN;
  int num = 0;
  int result = 1;
  char filename[FILENAME_LEN] = {'\0'};
  
  printf("Open a file\n>./");
  if(read_string(filename, FILENAME_LEN)) {
    printf("Bad filename. Program exits.\n");
    return EXIT_FAILURE;
  }
  my_file = fopen(filename, "r");
  if (my_file == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  } else {
    printf("File was opened.\n");
  }
  while (!feof(my_file) && result) {
    if (fgets(str, LINESIZE, my_file) != NULL) {
      result = sscanf(str, "%d", &num);
      if (result) {
        if (num > max && result)
          max = num;
        if (num < min && result)
          min = num;
        linecount++;
      }
    }
  }
  printf("Numbers read: %d\n", linecount);
  printf("Min: %d\nMax: %d\n", min, max);
  fclose(my_file);
  return EXIT_SUCCESS;
}
