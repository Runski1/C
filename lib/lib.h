#ifndef LIB_H
#define LIB_H

// Function declarations for the files in ../lib
void clear_input_buffer(void);
int random_int_in_range(int min, int max);
int read_integer(void);
int read_range(int low, int high);
bool read_string(char *str, int max_strlen);
int replace_char(char *str, const char *repl);

#endif // LIB_H

