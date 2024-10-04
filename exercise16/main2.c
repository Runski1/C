#include "../lib/read_input.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRLEN 80

/* AFAIK structures exist only to the end of the translation unit (this file)
 * so a structure defined in global scope *should* be ok
 * */
typedef struct node {
    int number;
    struct node *next;
} nnode;

nnode *add_node(int number, nnode **head, nnode **tail) {
    nnode *new = NULL;
    new = malloc(sizeof(nnode));
    if (new == NULL) {
        printf("malloc error");
        return NULL;
    }
    new->number = number; 
    new->next = NULL;
    if (*head == NULL) { // in case it's the first node
        *head = new; // point head ...
        *tail = new; // ... and tail to the new node
    } else {
        (*tail)->next = new; // else point the last node's next to the new one
        (*tail) = new; // update tail
    }
    return *tail; // the return value here is kinda redundant
}

void print_nodes(nnode *head) {
    int i = 1;
    while (head != NULL) {
        printf("Item %2d : %d\n", i, head->number);
        i++;
        head = head->next;
    };
}
void remove_nodes(nnode *head) {
    while (head != NULL) {
        nnode *dobby = head;
        head = head->next;
        free(dobby);
    }
}

int main(void) {
    char user_string[MAX_STRLEN] = {'\0'};
    int ret_val = 0;
    long int read_num = 0;
    nnode *tail = NULL;
    nnode *head = NULL;
    char *end = NULL;

    while (strcmp(user_string, "end") != 0) {
        ret_val = read_string(user_string, MAX_STRLEN, stdin);
        if (!ret_val) {
            errno = 0;
            read_num = strtol(user_string, &end, 10);
            if (errno == ERANGE) {
                printf("Input out of range.\n");
            }
            if (!errno && (INT_MIN <= read_num && read_num <= INT_MAX) &&
                *end == '\0') {
                tail = add_node((int)read_num, &head, &tail);
            } else { // this block executes usually on end or when the input
                // didn't consist only of numbers
                if (strcmp(user_string, "end") != 0) {
                    printf("Bad input.\n");
                }
            }
        }
    }

    print_nodes(head);
    remove_nodes(head);

    return EXIT_SUCCESS;
}
