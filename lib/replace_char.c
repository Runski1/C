#include <string.h>

int replace_char(char *str, const char *repl) {
  int count = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == repl[0]) {
      str[i] = repl[1];
      count += 1;
    }
  }
  return count;
}
