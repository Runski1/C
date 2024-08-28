#include <stdio.h>

/* Got finally bored of validating inputs on the fly */
int get_validated_int(void) {
  int input, result;

  while (1) {
    /* if I were to clear input buffer here, it would lead
     * to unexpected behaviour with the first input*/
    result = scanf("%d", &input);
    if (result == 1) {
      while (getchar() != '\n') {} // So I do it twice, here for inputs such as "3LOL"
      break;
    } else {
      while (getchar() != '\n') {} // and here if no integer is found in input
      printf("Please enter an integer: ");
    }
  }
  return input;
}

int main(void) {

  int student_count = 0, selected_student = -1, default_grade = -1,
      given_grade = 1;

  printf("How many students: ");
  student_count = get_validated_int();

  int students[student_count];
  /* note to future self who is never goint to read this, 
   * if for some reason I ever change students from int
   * to something else, this next loop sizing would break if it was
   * divided sizeof(int) instead of sizeof(student[0]) */
  for (int i = 0; i < (sizeof(students) / sizeof(students[0])); i++) {
    students[i] = default_grade;
  } // are for loops really so bad?

  do { // loop to select students, 0 to print
    printf("Enter student number (1-%d) or 0 to stop: ", student_count);
    selected_student = get_validated_int();

    // this is where the program ends, with the final print
    if (selected_student == 0) {
      printf("%10s %10s\n", "Student", "Grade");
      for (int i = 0; i < student_count; i++) {
        if (students[i] != -1) {
          printf("%10d %10d\n", i + 1, students[i]);
        } else {
          printf("%10d %10s\n", i + 1, "N/A");
        }
      }
      return 0; // Student selection loop is never broken before this return statement, I
                // wonder if it's ok...

      /* Loop until valid grade is gotten */
    } else if (0 < selected_student && selected_student <= student_count) {
      while (1) {
        printf("Enter grade (0-5) for student %d or -1 to cancel: ",
               selected_student);
        given_grade = get_validated_int();
        if (0 <= given_grade &&
            given_grade <= 5) { // -1 is NOT valid grade in this case, since it
                                // would overwrite the grade
          students[selected_student - 1] = given_grade;
          break;
        } else if (given_grade == -1) {
          break;
        } else {
          printf("Invalid grade!\n");
        }
      }
    } else {
      printf("Invalid student number!\n");
    }
  } while (selected_student != 0);
}
