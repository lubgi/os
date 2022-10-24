#include "student.h"
#include <stdio.h>
#include <stdlib.h>


Student* get_students_with_failed_subjects(Student students[], int students_count, int* out_failed_stuents_count);
double get_excellent_students_percent(Student students[],  int students_count);
Subject get_easiest_subject(Student students[],  int students_count);
int get_worst_group_number(Student students[],  int students_count);
Student enter_student_info();

int main(){
    Student students[30];
    int students_count;
    printf("Enter students count (<=30): ");
    scanf("%d", &students_count);

    //enter students
    for (int i = 0; i < students_count; i++)
    {
        students[i] = enter_student_info();
    }

    //print students

    for (int i = 0; i < students_count; i++)
    {
        student_print(students[i]);
    }

    int failed_students_count = 0;
    Student* failed_students = get_students_with_failed_subjects(students, students_count, &failed_students_count);
    for (int i = 0; i < failed_students_count; i++)
    {
        printf("\nFailed students: \n");
        student_print(failed_students[i]);
    }
    

    printf("\nExcellent students percent = %f", get_excellent_students_percent(students, students_count));

    printf("\nEasiest subject: %s ", get_easiest_subject(students, students_count).name);

    printf("\nGroup number with worst efficiency: %d", get_worst_group_number(students, students_count));

}

Student enter_student_info(){
    char lastname[12];
    int group_number;
    //int scores[3];
    int* scores = malloc(3*sizeof(int));

    printf("Enter student lastname: ");
    scanf("%s", lastname);

    printf("Enter student group number (between 1 and 4): ");
    scanf("%d", &group_number);

    printf("Enter score for Web technologies: ");
    scanf("%d", &scores[0]);

    printf("Enter score for Ukranian language: ");
    scanf("%d", &scores[1]);

    printf("Enter score for Design of information systems:");
    scanf("%d", &scores[2]);

    return student_init(lastname, group_number, scores);
}

Student* get_students_with_failed_subjects(Student students[], int students_count, int* out_failed_stuents_count){
    
    Student* failed_students = malloc(30*sizeof(Student));
    int failed_students_count = 0;

    for (int i = 0; i < students_count; i++)
    {
        if (student_has_failed_subject(students[i]))
        {
            failed_students[failed_students_count++] = students[i];
            break;
        }
    }

    *out_failed_stuents_count = failed_students_count;
    return failed_students;
}

double get_excellent_students_percent(Student students[],  int students_count){
    int excellent_students = students_count;
    for (int i = 0; i < students_count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (students[i].subjects[j].score < 80)
            {
                excellent_students--;
                break;
            }
        }
    }

    return (double)excellent_students * 100 / (double)students_count;
}

Subject get_easiest_subject(Student students[],  int students_count){
    Subject* subjects = student_subject_array();
    for (int i = 0; i < students_count; i++)
    {
        subjects[0].score+=students[i].subjects[0].score;
        subjects[1].score+=students[i].subjects[1].score;
        subjects[2].score+=students[i].subjects[2].score;
    }


    int highest_value = subjects[0].score;
	int index = 0;
	for(int i = 0; i < 3; i++) {
		if(highest_value < subjects[i].score) {
			highest_value = subjects[i].score;
			index = i;
		}
	}

    return subjects[index];
}

int get_worst_group_number(Student students[], int students_count){
    int groups_scores_sum[4] = {0, 0, 0, 0};

    for (int i = 0; i < students_count; i++)
    {
        groups_scores_sum[students[i].group_number-1]+= students[i].subjects[0].score +
                                                        students[i].subjects[1].score +
                                                        students[i].subjects[2].score;
    }
    
    int lowest_value = groups_scores_sum[0];
	int index = 0;
	for(int i = 0; i < 4; i++) {
		if(lowest_value < groups_scores_sum[i]) {
			lowest_value = groups_scores_sum[i];
			index = i;
		}
	}

    return index+1;
}