#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "list.h"
#include <errno.h>

char* getStudentData(Student* student) {
    char* studentData = malloc(256); 
    if (studentData == NULL) {
        perror("Ошибка при выделении памяти для строки с данными студента");
        return NULL;
    }
    snprintf(studentData, 256, "Имя: %s, Фамилия: %s, Возраст: %d, Пол: %s, Группа: %s, Оценки: Математика - %d, Физика - %d, Химия - %d",
             student->name, student->surname, student->age, student->gender, student->group,
             student->mathGrade, student->physicGrade, student->chemistryGrade);
    return studentData;
}

void writeStudentsToFile(List* StudentList, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка при создании файла");
        return;
    }

    Node* current = StudentList->head;
    while (current != NULL) {
        Student* student = current->student; 
        char* studentData = getStudentData(student);
        if (studentData != NULL) {
            fprintf(file, "%s\n", studentData); 
            free(studentData); 
        }
        current = current->next;
    }

    fclose(file);
}

void readStudentsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла для чтения");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList(NULL);
    if (StudentList == NULL) {
        return 1;
    }

    AppendData appendData = { StudentList, NULL };

    appendData.student = InitStudent((void* []) { "Ivan", "Tfgd", "ghfdsf", "ghgjf4", "23", "4", "2", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Vaho", "Tfgd", "gtjап", "ghgjf4", "14", "4", "4", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Timur", "Tfgd", "ыпвимч", "ghgjf4", "17", "4", "3", "3" });
    Append(&appendData);

    UpData upData = { StudentList, 0 };

    for (int i = 0; i < StudentList->size; i++) {
        upData.index = i;
        Up(&upData);
    }
    PrintList(StudentList);
    writeStudentsToFile(StudentList, "students.txt");
    readStudentsFromFile("students.txt");
    printf("Нажмите Enter для продолжения...");
    getchar();
    FreeList(StudentList);
    return 0;
}