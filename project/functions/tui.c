#include "func.h"
#include <stdio.h>
#include "macros.h"
#include <stdlib.h>

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

