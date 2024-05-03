#include <stdlib.h>
#include "student.h"

void* InitStudent(void* args) {
    char** params = (char**)args;
    Student* student = malloc(sizeof(Student));
    if (student == NULL) {
        return NULL;
    }
    student->name = params[0];
    student->surname = params[1];
    student->gender = params[2];
    student->group = params[3];
    student->age = atoi(params[4]);
    student->mathGrade = atoi(params[5]);
    student->physicGrade = atoi(params[6]);
    student->chemistryGrade = atoi(params[7]);
    return student;
}