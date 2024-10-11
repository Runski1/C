#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LOW PRIORITY stop harry potter jokes and rename */
void free_dobby(char *selection, char **rooms, int maxlen_rooms) {
    free(selection);
    int i = 0;
    while (i < maxlen_rooms) {
        free(rooms[i]);
        i++;
    }
}
void clear_ibuf(void) {
    char c;
    while ((c = getchar()) != EOF && c != '\n') {
    }
}

void print_error(const char *file, const char *function, int line, char *str) {
    fprintf(stderr, "%s:%s:%d:\n%s\n", file, function, line, str);
    if (errno) {
        fprintf(stderr, "%s", strerror(errno));
    }
}

int read_integer() {
    char input_string[64];
    char *endptr; // for strtol
    long long int input_number = 0;
    do { // read while a clean, nice number is read
        do { // read input until a valid number is entered; also stuff like 932xyz
            // exits this loop
            errno = 0;
            // if cannot read a number
            if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
                print_error(__FILE__, __FUNCTION__, __LINE__,
                            "fgets error reading input.\n");
            }
            // if input is too long 
            if (strchr(input_string, '\n') == NULL) {
                print_error(__FILE__, __FUNCTION__, __LINE__,
                            "Input too long.\n");
                clear_ibuf();
            }
        } while (strchr(input_string, '\n') == NULL);
        errno = 0;
        input_number = strtol(input_string, &endptr, 10);

        // if it doesn't fit within INT limits
        if (errno == ERANGE || input_number < INT_MIN ||
            input_number > INT_MAX) {
            errno = ERANGE;
            print_error(__FILE__, __FUNCTION__, __LINE__,
                        "");
        } // if it doesn't contain only numbers and \n or \0
        if ((*endptr != '\n' && *endptr != '\0')) {
            print_error(__FILE__, __FUNCTION__, __LINE__, "Invalid input.\n");
        }
    } while (endptr == input_string || errno == ERANGE ||
             (*endptr != '\n' && *endptr != '\0'));

    return (int)input_number;
}

int read_range(int low, int high, char *str) {
    int chosen_num = 0;
    do {
        chosen_num = read_integer();
        if (chosen_num < low || chosen_num > high) {
            printf("Choose a number between %d and %d\n", low, high);
        }
    } while (low > chosen_num || high < chosen_num);
    return chosen_num;
}
