#ifndef INPUT_LIB
#define INPUT_LIB

#include <stdio.h>

void free_dobby(char *selection, char **rooms, int maxlen_rooms);
void clear_ibuf();
int read_line(char *str, int max_strlen, FILE *file);
void print_temperature(char *choice, char *room_name, float *temperature);
FILE *open_file(char *filename, char *mode);
int read_from_csv(char *str, char *filename, int line_length, char **rooms, \
                  char *selected_room, float *temperature);
void get_rooms(char *line);
int parse_line(char *line, char *choice, float *temperature, char **rooms);

#endif

