#ifndef UTILS
#define UTILS

#include <stdio.h>

void free_dobby(char *selection, char **rooms, int maxlen_rooms);
void clear_ibuf();
void print_error(const char *file, const char *function, int line, char *str);
int read_integer();
int read_range(int low, int high, char *str);

#endif

