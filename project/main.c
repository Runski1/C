#include "./functions/csv_functions.h"
#include "./functions/utils.h"
#include "./functions/tui_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./functions/macros.h"


int main(void) {

    char line[LINE_LENGTH] = {'\0'};
    char *rooms[MAX_ROOMS] = {NULL};
    char *selection = NULL;
    float temperature = 0;

    /* read the room names */
    if (read_from_csv(line, CSV_FILE, LINE_LENGTH, rooms, NULL, NULL)) {
        free_dobby(selection, rooms, MAX_ROOMS);
        return EXIT_FAILURE;
    }
    /* TUI */
    selection = strdup(TUI(rooms));
    if (selection == NULL) {
        /* if error */
        fprintf(stderr, "%s%s%d:\nMemory allocation failure", __FILE__,\
                __FUNCTION__, __LINE__);
        free_dobby(selection, rooms, MAX_ROOMS);
        return EXIT_FAILURE;
    }

    /* read csv file again, print out temperature if room matches
     * The printing function is chained:
     * read_from_csv>read_line>parse_line>print_temperature
     * I'm not a huge fan of chaining functions, maybe will change
     * LOW PRIORITY
     * */
    printf("%s", selection); // This should be moved, print temperature header line
    if(read_from_csv(line, CSV_FILE, LINE_LENGTH, NULL, selection, &temperature)) {
        free_dobby(selection, rooms, MAX_ROOMS);
        return EXIT_FAILURE;
    }
    /* memory is freed on successful run*/
    /* LOW PRIORITY stop harry potter jokes and rename */
    free_dobby(selection, rooms, MAX_ROOMS);
    printf("\n");
    return EXIT_SUCCESS;
}
