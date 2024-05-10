#include <stdlib.h>
#include "student.h"
#include <errno.h>
#include <stdio.h>
#include <locale.h>

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

char* getStudentData(Student* student) {
    char* studentData = malloc(256); 
    if (studentData == NULL) {
        perror("Ошибка при выделении памяти для строки с данными студента");
        return NULL;
    }
    snprintf(studentData, 256, "Name: %s, Surname: %s, Age: %d, Gender: %s, Group: %s, estimation: Mathematics - %d, Physics- %d, Chemistry - %d",
             student->name, student->surname, student->age, student->gender, student->group,
             student->mathGrade, student->physicGrade, student->chemistryGrade);
    return studentData;
}