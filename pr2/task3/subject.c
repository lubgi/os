#include "subject.h"
#include <string.h>
#include <stdio.h>

Subject subject_init(char name[], int score){
    Subject subject;
    strcpy(subject.name, name);
    subject.score = score;
    printf("zalupa");
    return subject;
}

void subject_print(Subject subject){
    printf("Subject name: %s, score = %d", subject.name, subject.score);
}