#include <stdio.h>

void clear_input_buffer(void) {
  while (getchar() != '\n')
    ;
}

/* got bored of writing input validations
 * so might aswell write a function for it
 *
 * I CBA to write one that can take different parameters in,
 * for example strings for printf's and such. Did try at first,
 * but The way some of the prompts for user input include nested integers,
 * I would've had to craft strings before passing them in variables. so CBA*/
int get_validated_int(void) {
  int input, result;
  char term;

  while (1) {
    result = scanf("%d%c", &input, &term);
    /* not my own idea to find EOF in input buffer, but
     * IIUC user might end input with ctrl+D or similar, which
     * would in turn put EOF in the buffer*/
    while (term != '\n' && term != EOF) {
      clear_input_buffer();
    }
    if (result == 2 &&
        term == '\n') { // 2, not 1: scanf should match input AND term
      // I think there's a bug here if user inputs EOF after valid int
      return input;
    }
  }
}

int main(void) {

  int student_count = 0, selected_student = -1, default_grade = -1,
      given_grade = 1;

  printf("How many students: ");
  student_count = get_validated_int();
  printf("Student's added: %d \n", student_count);

  int students[student_count]; // init students-array
  for (int i = 0; i < (sizeof(students) / sizeof(students[0])); i++) {
    students[i] = default_grade;
  }

  do { // loop to select students, 0 to print
    printf("Enter student number (1-%d) or 0 to stop: ", student_count);
    selected_student = get_validated_int();

    if (selected_student == 0) { // final print
      printf("%10s %10s\n", "Student", "Grade");
      for (int i = 0; i < student_count; i++) {
        if (students[i] != -1) {
          printf("%10d %10d\n", i + 1, students[i]);
        } else {
          printf("%10d %10s\n", i + 1, "N/A");
        }
      }
      return 0; // Student selection loop is broken by the return statement, I
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
