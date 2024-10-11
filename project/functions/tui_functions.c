#include "macros.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TUI(char **rooms) {
  int choice = 0, i = 0;
  do {
    i = 0;
    CLEAR_TERMINAL // defined in macros.h, for win and linux
    printf("Show room temperature records>\n");
    while (i < MAX_ROOMS && rooms[i] != NULL) {
      printf("(%d) %s\n", i + 1, rooms[i]);
      i++;
    }
    choice = read_range(1, i, "");
  } while (choice < 1 || choice > i); // i instead of i+1 since it's ++'d once
  return rooms[choice - 1];
}

void print_temperature(char *choice, char *room_name, float *temperature) {
  /* Do the nice print
  */
  int i = 0;
  printf("\n%4.1f\u00B0C ", *temperature);
  if (*temperature >= 0 && *temperature <= 30) {
    while (i < ((int)(*temperature * 2))) { // this trunks, good enough
      printf("-");
      i++;
    }
  } else {
    printf("X");
  }
}
