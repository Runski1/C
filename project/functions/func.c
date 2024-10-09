#include "func.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_ibuf(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
char * TUI(char **rooms) {
    int choice = 0, i = 0;
    do {
        i = 0;
        CLEAR_TERMINAL
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
        printf("\n%.1f\u00B0C ", *temperature);
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

void parse_line(char *line, char *choice, float *temperature, char **rooms) {
    int ret_val = 0;
    char room_name[ROOM_NAME_LEN] = {'\0'};
    sscanf(line, "%*s,%*s"); // dump the headers
    if (choice == NULL) {
        ret_val = sscanf(line, "%*f,%49[^\r\n]", room_name);
        int i = 0, found = 0, j = 0;
        while (rooms[j] != NULL) {
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
        }
    } else if ((ret_val = sscanf(line, "%f,%49[^\r\n]", temperature,
                                 room_name)) == 2) {
        print_temperature(choice, room_name, temperature);
    }
}

FILE *open_file(char *filename, char *mode) {

    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "File %s couldn't be opened.\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
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
