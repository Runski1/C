#include <stdbool.h>
#include <stdio.h>
#define MAX_STRLEN 0xFF
#define FORMATTER_LEN 4 // 2c+\n+\0
// NOTE
// In excercise 7, I prevented a too long input from flooding into second and
// third execution loop by checking if linefeed existed in the input.
// Since I'm using the same function read_string here, I need to allocate
// 4 bytes for the formatter-string instead of 3.
// I could also not check the return value of read_string OR modify the existing
// function in a way that I can choose whether to check for \n or not.
// I chose to do neither and just allocate 4 bytes for the formatter-string.

int read_string(char *str, int max_strlen);
int replace_char(char *str, const char *repl);

/* Initially I planned to get fancy with different return values that
 * read_string can output. I should ask what could be the best way to handle
 * those, when there are multiple function calls happening in main.
 *
 * However, replaced_chars will ALWAYS be 0 if either of the read_string-calls
 * return something else than 0. I think "String was not modified" to be good
 * enough print for those cases too.
 * */
int main(void) {
  char str[MAX_STRLEN] = {'\0'};
  char formatter[FORMATTER_LEN] = {'\0'};
  int replaced_chars = 0;
  int return_val = 0;
  printf("Enter a string to modify:\n>");
  if (!read_string(str, MAX_STRLEN)) {
    printf("Enter the two characters (\"ab\" replaces every 'a' in your string"
           " with a 'b'):\n>");
    if (!read_string(formatter, FORMATTER_LEN)) {
      replaced_chars = replace_char(str, formatter);
    }
  }
  if (replaced_chars == 0) {
    printf("String was not modified.\n");
  } else {
    printf("%s\nNumber of characters replaced: %d\n", str, replaced_chars);
  }

  return 0;
}
