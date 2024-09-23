#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_STRLEN 0xFFF // this is capped by my OS or Terminal emulator
#define MAX_WORDLEN 0xFF

void clear_input_buffer(void);
int read_string(char *str, int max_strlen);

int count_words(const char *str, const char *word) {
  int count = 0;
  char *pos = (char *)str;
  while (pos) {
    pos = strstr(pos, word);
    if (pos) {
      count++;
      pos += strlen(word);
    }
  }
  return count;
}

int main(void) {
  char str[MAX_STRLEN] = {'\0'};
  char word[MAX_STRLEN] = {'\0'};
  int match_count = 0;
  int return_val = 0;
  do {
    printf("Enter some text:\n>");
    return_val = read_string(str, MAX_STRLEN);
    if (!return_val) {
      printf("Enter a word you wish to search for in your text (\"stop\" to quit):\n>");
      return_val = read_string(word, MAX_WORDLEN);
      if (!return_val) {
        match_count = count_words(str, word);
      }
    }
    switch (return_val) {
      case 1:
        printf("Your string is too long.\n");
        break;
      case -1:
        printf("\nEOF detected. Program ends.\n");
        return 0;
      default:
        printf("Your word \"%s\" was found %d times.\n", word, match_count);
    }
  } while (strcmp(word, "stop") != 0);
  return 0;
}
