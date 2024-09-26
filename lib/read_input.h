#ifndef INPUT_LIB
#define INPUT_LIB

#include <stdbool.h> // Tbh I'm not a fan of boolean return type

void clear_input_buffer(void);
int read_integer(void);
int read_range(int low, int high);
bool read_string(char *str, int max_strlen);

#endif

