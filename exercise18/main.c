#include "../lib/read_input.h"
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_NUM 15

int num2random_hex(int num) {
    int rand_num = rand();
    printf("Your random number: 0x%08X\n", rand_num);
    int hex = (rand_num >> num) & 0x0000003F;
    return hex;
}

int main(void) {
    srand(time(NULL));
    int num = 1;
    while (num >= 0) {
        char *str = "Enter a number between 0 and 15 (or negative to stop)\n>";
        num = read_range(INT_MIN, MAX_NUM, str);
        if (num >= 0) {
            printf("0x%02X\n", num2random_hex(num));
        }
    }
    return 0;
}
