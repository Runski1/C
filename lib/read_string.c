#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void clear_input_buffer(void);

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
