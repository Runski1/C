#include <stdio.h>
#include <stdbool.h>
#define MAX_STRLEN 200
#define FORMATTER_LEN 4 // 2c+\n+\0
// NOTE
// In excercise 7, I prevented a too long input from flooding into second and
// third execution loop by checking if linefeed existed in the input.
// Since I'm using the same function read_string here, I need to allocate
// 4 bytes for the formatter-string instead of 3.
// I could also not check the return value of read_string OR modify the existing
// function in a way that I can choose whether to check for \n or not.
// I chose to do neither and just allocate 4 bytes for the formatter-string.

bool read_string(char *str, int max_strlen);
int replace_char(char *str, const char *repl);

int main(void) {
    char str[MAX_STRLEN] = {'\0'};
    char formatter[FORMATTER_LEN] = {'\0'};
    int replaced_chars = 0;
    printf("Enter a string to modify:\n>");
    if (read_string(str, MAX_STRLEN)) {
        printf("Enter the two characters (\"ab\" replaces every 'a' in your string with a 'b'):\n>");
        if(read_string(formatter, FORMATTER_LEN)) {
            replaced_chars = replace_char(str, formatter);
        }
    }
    if (replaced_chars == 0) {
        printf("String was not modified.\n");
    } else {
        // Note: no linefeed after str, str ALWAYS ends with linefeed
        printf("%sNumber of characters replaced: %d\n", str, replaced_chars);
    }

    return 0;
}
