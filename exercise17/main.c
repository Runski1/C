#include "../lib/read_input.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define WORD_LENGTH 32
#define EXT_SIZE(x) x * 2 + 1

bool passwordify(char *pwd, int array_size, const char *word) {
    int length = strlen(word);
    int password_length = EXT_SIZE(length);
    if (password_length > array_size) { // the way I wrote this, array_size
                                        // isn't strictly needed here
        // I think I didn't fully understand the assignment.
        return false; // I dont think this will ever trigger
    }
    for (int i = 0; i < EXT_SIZE(WORD_LENGTH); i++) {
        pwd[i] = '\0';
    }
    /* The length of the soon to be produced password is already known.
     * First bit changes all the characters that are included in final password
     * to random printable ASCII (95 characters from 32 onwards)
     * leaving the rest in 32 character array as \0
     * */
    for (int j = 0; j < password_length; j++) {
        pwd[j] = (char)(rand() % 95 + 32);
    }
    /* for a while I had cool pointer arithmetics here but then I realized
     * it totally wasn't needed :(
     * */
    for (int i = 0; i < length; i++) {
        pwd[EXT_SIZE(i)] = word[i];
    }

    return true;
}

int main(void) {
    srand(time(NULL));
    char password[EXT_SIZE(WORD_LENGTH)] = {'\0'};
    char word[WORD_LENGTH] = {'\0'};
    bool not_stop = true;

    int ret_val = 0;
    while (not_stop) {
        ret_val = read_string(word, WORD_LENGTH, stdin);
        if (strcmp(word, "stop") == 0) {
            not_stop = false;
        }

        if (!ret_val && not_stop) {
            if (passwordify(password, EXT_SIZE(WORD_LENGTH), word)) {
                printf("%s\n", password);
            } else {printf("You somehow managed to trigger this warning.\n");}
        } else if (ret_val == 1) {
            printf("Input too long. (max %d characters)\n", WORD_LENGTH);
        }
    }

    return 0;
}
