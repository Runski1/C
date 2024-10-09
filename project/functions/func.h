#ifndef INPUT_LIB
#define INPUT_LIB

#include <stdio.h>

void clear_ibuf();
int read_line(char *str, int max_strlen, FILE *file);
void print_temperature(char *choice, char *room_name, float *temperature);
FILE *open_file(char *filename, char *mode);
void get_rooms(char *line);
void parse_line(char *line, char *choice, float *temperature, char **rooms);

#endif

