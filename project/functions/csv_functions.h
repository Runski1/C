#ifndef CSV_FUNCTIONS
#define CSV_FUNCTIONS

#include <stdio.h>

int parse_line(char *line, char *choice, float *temperature, char **rooms);
FILE *open_file(char *filename, char *mode);
int read_from_csv(char *str, char *filename, int line_length, char **rooms,
                  char *selected_room, float *temperature);
int read_line(char *str, int max_strlen, FILE *file);

#endif

