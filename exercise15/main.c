#include "../lib/read_input.h"
#include <complex.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#define MENU_ITEMS 40
#define FILENAME_LEN 30
#define LINESIZE 80

int main(void) {
  FILE *menu_file = NULL;
  char filename[FILENAME_LEN];
  typedef struct menu_item_ {
    char name[50];
    double price;
  } menu_item;
  menu_item menu_items[MENU_ITEMS] = {{"", 0}};

  errno = 0;
  menu_file = open_file(filename, sizeof(filename), "r");
  if (menu_file == NULL) {
    if (errno != 0) {
      perror(filename);
    }
    return EXIT_FAILURE;
  }
  int ret_val = 2;
  int i = 0;
  while (ret_val == 2 && i < MENU_ITEMS) {
    ret_val = fscanf(menu_file, "%[^;]; %lf\n", menu_items[i].name,
                     &menu_items[i].price);
    i++;
  }
  i = 0;
  while (menu_items[i].name[0] != '\0' && i < MENU_ITEMS) {
    printf("%8.2lf %s\n", menu_items[i].price, menu_items[i].name);
    i++;
  }
  return 0;
}
