#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void clear_input_buffer(void);

bool read_string(char *str, int max_strlen) {
  char *nullfinder;
  nullfinder = fgets(str, max_strlen, stdin);
  if (strchr(nullfinder, '\n') == NULL) {
    clear_input_buffer();
    return false;
  } else {
    return true;
  }
}
