#include "./functions/func.h"
#include "./functions/tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./functions/macros.h"


int main(void) {

    char line[LINE_LENGTH] = {'\0'};
    FILE *file = open_file(CSV_FILE, "r");
    char *rooms[MAX_ROOMS] = {NULL};
    char *selection = NULL;
    int ret_val = 0;
    float temperature = 0;
    while (!ret_val && !feof(file)) {
        if ((ret_val = read_line(line, LINE_LENGTH, file)) > 0) {
            fprintf(stderr, "File reading error: reading a line failed.\n");
        }
        parse_line(line, NULL, NULL, rooms);
    }
    fclose(file);
    selection = strdup(TUI(rooms)); // TUI call
    ret_val = 0;
    file = open_file(CSV_FILE, "r");
    printf("%s", selection);
    while (!ret_val && !feof(file)) {
        if ((ret_val = read_line(line, LINE_LENGTH, file)) > 0) {
            fprintf(stderr, "File reading error: reading a line failed.\n");
        }
        if (!ret_val) {
            parse_line(line, selection, &temperature, NULL);
        }
    }
    free(selection);
    fclose(file);
    printf("\n");
    int i = 0;
    while (i < MAX_ROOMS) {
        free(rooms[i]);
        i++;
    }
}
