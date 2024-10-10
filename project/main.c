#include "./functions/func.h"
#include "./functions/tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./functions/macros.h"



int main(void) {

    char line[LINE_LENGTH] = {'\0'};
    char *rooms[MAX_ROOMS] = {NULL};
    char *selection = NULL;
    float temperature = 0;

    if (read_from_csv(line, CSV_FILE, LINE_LENGTH, rooms, NULL, NULL)) {
        free_dobby(selection, rooms, MAX_ROOMS);
        return EXIT_FAILURE;
    }
    selection = strdup(TUI(rooms)); // TUI call
    if (selection == NULL) {
        fprintf(stderr, "%s%s%d:\nMemory allocation failure", __FILE__,\
                __FUNCTION__, __LINE__);
        free_dobby(selection, rooms, MAX_ROOMS);
        return EXIT_FAILURE;
    }

    printf("%s", selection); // This should be moved, print temperature header line
    if(read_from_csv(line, CSV_FILE, LINE_LENGTH, NULL, selection, &temperature)) {
        free_dobby(selection, rooms, MAX_ROOMS);
        return EXIT_FAILURE;
    }
    free_dobby(selection, rooms, MAX_ROOMS);
    printf("\n");
    return EXIT_SUCCESS;
}
