#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "student.h"

void* InitStudent(void* args) {
    char** params = (char**)args;
    Student* student = malloc(sizeof(Student));
    if (student == NULL) {
        perror("Ошибка при выделении памяти для студента");
        return NULL;
    }

    if (params[0] == NULL || params[1] == NULL || params[2] == NULL || params[3] == NULL ||
        params[4] == NULL || params[5] == NULL || params[6] == NULL || params[7] == NULL) {
        fprintf(stderr, "Недостаточно параметров для инициализации студента\n");
        free(student); 
        errno = EINVAL; 
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

    if (errno != 0) {
        perror("Ошибка при преобразовании строки в число");
        free(student); 
        return NULL;
    }

    return student;
}