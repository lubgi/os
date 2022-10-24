typedef struct
{
    char name[30];
    int score;
} Subject;

Subject subject_init(char name[], int score);
void subject_print(Subject subject);