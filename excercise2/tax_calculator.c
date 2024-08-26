#include <stdio.h>

float tax_rate = 10, income_limit = 10000, tax_rate_over_limit = 20,
      incomes[12], taxes[12], user_input, running_sum = 0;

void clear_input_buffer(void) {
  while (getchar() != '\n')
    ;
}

int main(void) {
  /* init */
  for (int i = 0; i < sizeof(taxes) / sizeof(float); i++) {
    taxes[i] = 0;
  }

  do {
    printf("Enter tax rate: ");
    if (scanf("%f", &tax_rate) == 1) {
      break;
    } else {
      clear_input_buffer();
    }
  } while (1);

  do {
    printf("Enter income limit: ");
    if (scanf("%f", &income_limit) == 1) {
      break;
    } else {
      clear_input_buffer();
    }
  } while (1);

  do {
    printf("Enter tax rate for income over the limit: ");
    if (scanf("%f", &tax_rate_over_limit) == 1) {
      break;
    } else {
      clear_input_buffer();
    }
  } while (1);

  /* Populate incomes array */
  for (int i = 1; i <= sizeof(incomes) / sizeof(float); i++) {
    while (1) {
      printf("Enter income for month %d: ", i);
      if (scanf("%f", &incomes[i - 1]) == 1) {
        break;
      } else {
        clear_input_buffer();
      }
    }
  }

  /* Calculate the tax */
  for (int i = 0; i < sizeof(incomes) / sizeof(float); i++) {
    if (running_sum > income_limit) {
      taxes[i] = (tax_rate_over_limit / 100) * incomes[i];
    } else {
      running_sum += incomes[i];
      if (running_sum > income_limit) {
        taxes[i] += (income_limit - (running_sum - incomes[i])) * (tax_rate / 100);
        taxes[i] += (running_sum - income_limit) * (tax_rate_over_limit / 100);
      } else {
        taxes[i] = (tax_rate / 100) * incomes[i];
      }
    }
  }

  /* Print the results */
  printf("%5s %15s %15s\n", "month", "income", "tax");
  for (int i = 1; i <= sizeof(incomes) / sizeof(float); i++) {
    printf("%5d %15.2f %15.2f\n", i, incomes[i - 1], taxes[i - 1]);
  }

  return 0;
}
