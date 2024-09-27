#ifndef INPUT_LIB
#define INPUT_LIB

#include <stdbool.h> // Tbh I'm not a fan of boolean return type
#include <stdio.h>

void clear_input_buffer(void);
int read_integer(void);
int read_range(int low, int high);
int read_string(char *str, int max_strlen, FILE *stream);
FILE * open_file(char* filename, const int filename_len, char *mode);

#endif

