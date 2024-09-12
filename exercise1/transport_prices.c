#include <stdio.h>

void clear_input_buffer(void) {
  while (getchar() != '\n')
    ;
}
int main(void) {

  float bus_price, taxi_price, user_money;
  int user_selection, valid_input = 0;

  while (!valid_input) {
    printf("Enter price of bus ticket: ");
    valid_input = scanf("%f", &bus_price);
    clear_input_buffer();
  }
  valid_input =
      0; // I feel like this is not the most elegant way of input validation
  while (!valid_input) {
    printf("Enter price of taxi: ");
    valid_input = scanf("%f", &taxi_price);
    clear_input_buffer();
  }
  valid_input = 0;
  while (!valid_input) {
    printf("How much money you have: ");
    valid_input = scanf("%f", &user_money);
    clear_input_buffer();
  }
  do {
    valid_input = 0;
    printf("You have %.2f euros left.\n", user_money);
    if (user_money < taxi_price && user_money < bus_price) {
      printf("You need to walk. Bye\n");
      return 0;
    }
    while (!valid_input) {
      printf("Do you want to take \n"
             "1) bus (%.2f euros)\n"
             "2) taxi (%.2f euros)\n"
             "Enter your selection: ",
             bus_price, taxi_price);
      valid_input = scanf("%d", &user_selection);
      clear_input_buffer();
    }
    switch (user_selection) {
    case 1:
      printf("You chose bus.\n");
      if (user_money < bus_price) {
        printf("You don't have enough money for bus.\n");
      } else {
        user_money -= bus_price;
      }
      break;
    case 2:
      printf("You chose taxi.\n");
      if (user_money < taxi_price) {
        printf("You don't have enough money for taxi.\n");
      } else {
        user_money -= taxi_price;
      }
      break;
    }
  } while (1);
}
