#include <stdio.h>

int read_integer(void);
int random_in_range(int min, int max);

int main(void) {
  int menu_option = 0;
  int roll = 0;
  printf("Welcome to DiceRoller!\nRoll a dice!\n");
  printf("Choose an option 1-3 and press ENTER:\n");
  do {
    printf("(1) Roll D6\n(2) Roll D10\n(3)Quit DiceRoller\n>");
    menu_option = read_integer();
    switch (menu_option) {
    case 1:
      roll = random_in_range(1, 6);
      break;
    case 2:
      roll = random_in_range(1, 10);
      break;
    case 3:
      printf("Thanks for \"playing\". Goodbye!\n");
      return 0;
    default:
      menu_option = 0;
    }
    if (!roll) {
      printf("Type in number 1, 2 or 3 and hit ENTER:\n");
    } else {
      printf("You rolled %d.\n", roll);
    }
    roll = 0;
  } while (menu_option != 3);
}
