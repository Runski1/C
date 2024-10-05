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
     * First, change all the characters that are included in final password
     * to random printable ASCII (95 characters from 32 onwards)
     * leaving the rest in 65 character array as \0
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
    bool stop = false;

    int ret_val = 0;
    while (!stop) {
        printf(
            "Enter a seed to generate password or 'stop' to quit program.\n> ");
        ret_val = read_string(word, WORD_LENGTH, stdin);
        if (strcmp(word, "stop") == 0) {
            stop = true;
        }

        if (!ret_val && !stop && word[0] != '\0') {
            if (passwordify(password, EXT_SIZE(WORD_LENGTH), word)) {
                printf("%s\n", password);
            } else {
                printf("You somehow managed to trigger this warning.\n");
            }
        } else if (ret_val == 1) {
            printf("Seed is too long. (max %d characters)\n", WORD_LENGTH);
        } else if (word[0] == '\0') {
            printf("The seed should have atleast 1 character.\n");
        }
    }

    return 0;
}
