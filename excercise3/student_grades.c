#include <stdio.h>

int student_count = 0, selected_student = -1, default_grade = -1,
    given_grade = 1;

void clear_input_buffer(void) {
  while (getchar() != '\n')
    ;
}

int main(void) {
  do {
    printf("How many students: ");
    if (scanf("%d", &student_count) != 1) {
      clear_input_buffer();
    }
  } while (student_count == 0);

  int students[student_count]; // init students-array
  for (int i = 0; i < (sizeof(students) / sizeof(students[0])); i++) {
    students[i] = default_grade;
  }

  do {
    printf("Enter student number (1-%d) or 0 to stop: ", student_count);
    if (scanf("%d", &selected_student) != 1) {
      clear_input_buffer();
    }
  } while (selected_student == -1);

  if (selected_student == 0) { // final print
    printf("%10s %10s", "Student", "Grade");
    for (int i = 0; i < student_count; i++) {
      if (students[i] != -1) {
        printf("%10d %10d", i + 1, students[i]);
      } else {
        printf("%10d %10s", i + 1, "N/A");
      }
    }
    return 0;
  } else {
    do {
      printf("Enter grade (0 - 5) for student %d or -1 to cancel: ",
             selected_student);
      if (scanf("%d", &given_grade) != 1) {
        clear_input_buffer();
      };
      if (given_grade > 5) {
        printf("Invalid grade!");
        given_grade = -1;
      }
    } while (given_grade < -1 || given_grade > 5);
    students[selected_student-1] = given_grade;
  }
}
