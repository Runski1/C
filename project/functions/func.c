#include "func.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_dobby(char *selection, char **rooms, int maxlen_rooms) {
    free(selection);
    int i = 0;
    while (i < MAX_ROOMS) {
        free(rooms[i]);
        i++;
    }
}
void clear_ibuf(void) {
    char c;
    while ((c = getchar()) != EOF && c != '\n') {
    }
}

char *TUI(char **rooms) {
    int choice = 0, i = 0;
    do {
        i = 0;
        // CLEAR_TERMINAL
        printf("Show room temperature records>\n");
        while (i < MAX_ROOMS && rooms[i] != NULL) {
            printf("(%d) %s\n", i + 1, rooms[i]);
            i++;
        }
        scanf("%d", &choice); // FIX THIS SHIT
        clear_ibuf();         ///////// Hotfixing shit
    } while (choice < 1 || choice > i); // i instead of i+1 since it's ++'d once
    return rooms[choice - 1];
}

void print_temperature(char *choice, char *room_name, float *temperature) {
    int i = 0;
    if (strcmp(choice, room_name) == 0) {
        printf("\n%4.1f\u00B0C ", *temperature);
        if (*temperature >= 0 && *temperature <= 30) {
            while (i < ((int)(*temperature * 2))) {
                printf("-");
                i++;
            }
        } else {
            printf("X");
        }
    }
}

int parse_line(char *line, char *choice, float *temperature, char **rooms) {
    /* This can operate two ways */
    /* Room name parsing mode args: line, NULL, NULL, rooms
     * Temperature parsing mode args : line, chosen_room, &temperature, NULL */
    int ret_val = 0;                        // catching scanf returns
    char room_name[ROOM_NAME_LEN] = {'\0'}; // where room name is stored

    sscanf(line, "%*s,%*s"); // dump the headers from csv

    /* Room name parsing mode */
    if (choice == NULL) {
        ret_val = sscanf(line, "%*f,%49[^\r\n]", room_name);
        int i = 0, found = 0, j = 0;
        while (rooms[j] != NULL) { //find free slot in array
            j++;
        }
        while (i <= j && !found && rooms[i] != NULL) {
            if (strcmp(rooms[i], room_name) == 0) {
                found = 1;
            }
            i++;
        }
        if (!found && i < MAX_ROOMS && room_name[0] != '\0') {
            rooms[j] = strdup(room_name);
            if (rooms[j] == NULL) {
                fprintf(stderr, "Memory allocation failure");
                return EXIT_FAILURE;
            }
        }

        /* Temperature parsing mode */
        /* If scanf doesn't scan exactly two values, the line is just skipped */
    } else if ((ret_val = sscanf(line, "%f,%49[^\r\n]", temperature,
                                 room_name)) == 2) {
        print_temperature(choice, room_name, temperature);
    }
    return EXIT_SUCCESS;
}

FILE *open_file(char *filename, char *mode) {

    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "File %s couldn't be opened.\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

int read_from_csv(char *str, char *filename, int line_length, char **rooms,
                  char *selected_room, float *temperature) {
    /* A line read from filename is stored to str. 
     * rooms, temperature and selected room can be NULL, depending
     * on parse_line mode used */

    FILE *file = open_file(filename, "r");
    int ret_val = 0; // to catch read_line return val
    int line_count = 1; // this is for error handling only

    while (!ret_val && !feof(file)) {
        if ((ret_val = read_line(str, LINE_LENGTH, file)) > 0) {
            fprintf(stderr, "File %s: bad data on line %d.\n", CSV_FILE,
                    line_count);
            fclose(file);
            return EXIT_FAILURE;
        }
        line_count++;
        if (parse_line(str, selected_room, temperature, rooms)) {
            return EXIT_FAILURE;
        }
    }
    fclose(file);
    return 0;
}

int read_line(char *str, int max_strlen, FILE *file) {
    char *return_value;
    return_value = fgets(str, max_strlen, file);
    if (return_value == NULL || strchr(str, '\n') == NULL) {
        if (feof(file)) {
            clearerr(file);
            return -1; // EOF
        }
        return 1; // Other invalid input, most likely too long line
    } else {
        char *linefeed = strchr(str, '\n');
        *linefeed = '\0';
        return 0;
    }
}
