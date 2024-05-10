#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int age;
    char* name;
    char* surname;
    char* gender;
    char* group;
    int mathGrade;
    int physicGrade;
    int chemistryGrade;
} Student;

void* InitStudent(void* args);
char* getStudentData(Student* student);

#endif