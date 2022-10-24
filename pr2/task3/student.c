#include "student.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Student student_init(char lastname[13], int group_number, int subject_scores[3]){
    if (group_number < 1 || group_number > 4)
    {
        perror("Wrong group number");
        exit(-1);
    }
    
    Student student;

    strcpy(student.lastname, lastname);

    student.group_number = group_number;

    student.subjects[0] = subject_init("Web technoogies", subject_scores[0]);
    student.subjects[1] = subject_init("Ukranian language", subject_scores[1]);
    student.subjects[2] = subject_init("Design of information services", subject_scores[2]);

    return student;
}

Subject* student_subject_array(){
    Subject* subjects = malloc(3*sizeof(Subject));
    subjects[0] = subject_init("Web technoogies", 0);
    subjects[1] = subject_init("Ukranian language", 0);
    subjects[2] = subject_init("Design of information services", 0);
    return subjects;
}

void student_print(Student student){
    printf("\nLastname: %s, group: %d, subjects: ", student.lastname, student.group_number);
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        subject_print(student.subjects[i]);
    }
}

bool student_has_failed_subject(Student student){
    for (int j = 0; j < 3; j++)
        {
            if (student.subjects[j].score < 50)
            {
                return true;
            }
        }
    return false;
}