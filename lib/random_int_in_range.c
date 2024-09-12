#include <stdlib.h>

int random_int_in_range(int min, int max){
  long range = (long) max - min + 1;
  int random_num = rand() % range + min;
  return random_num;
}
