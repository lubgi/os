#include "subject.h"
#include <stdbool.h>

typedef struct{
    char lastname[13];
    int group_number;
    Subject subjects[3];
} Student;

Student student_init(char lastname[], int group_number, int subject_scores[3]);
Subject* student_subject_array();
bool student_has_failed_subject(Student student);

void student_print(Student student);
