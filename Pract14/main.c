#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <errno.h>
#include "list.c"

void writeStudentsToFile(List* StudentList, char* filename){
    FILE* file = fopen(filename, "w");
    if (file == NULL){
        perror("Ошибка записи в файл.");
    }

    Node* current = StudentList->head;
    while (current != NULL)
    {
        Student* student = current->student;
        char* StudentData = getStudentData(student);
        if (StudentData != NULL){
            fputs(StudentData, file);
            fputs("\n", file);
            free(StudentData);
        } 

        current = current->next;      
    }

    fclose(file);
}

void readStudentsFromFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла для чтения");
    }

    int count;
    while ((count = fgetc(file)) != EOF) {
        putchar(count);
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

    appendData.student = InitStudent((void* []) { "Elena", "Sukhova", "15", "ISP-111", "23", "2", "2", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Timur", "Sharipov", "55", "SIS-234", "14", "4", "4", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Evgeniy", "Skufov", "44", "KS-543", "17", "5", "3", "3" });
    Append(&appendData);

    writeStudentsToFile(StudentList, "students.txt");
    readStudentsFromFile("students.txt");
    printf("Press Enter to continue...");
    getchar();
    return 0;
}
