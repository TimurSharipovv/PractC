#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include "list.c"

int saveFile(char* path, List* StudentList) {
    FILE* file = fopen(path, "wb");
    if (file == NULL) {
        perror("Ошибка при создании файла");
        return -1;
    }

    if (fwrite(StudentList, sizeof(List), 1, file) != 1) {
        perror("Ошибка при записи в файл");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

List* loadFile(char* path) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        perror("Ошибка при открытии файла для чтения");
        return NULL;
    }

    List* list = malloc(sizeof(List));
    if (list == NULL) {
        perror("Ошибка при выделении памяти для списка");
        fclose(file);
        return NULL;
    }

    if (fread(list, sizeof(List), 1, file) != 1) {
        perror("Ошибка при чтении из файла");
        free(list);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return list;
}

int main() {
    setlocale(LC_ALL, "Rus");
    List* StudentList = InitList(NULL);
    if (StudentList == NULL) {
        perror("Ошибка при инициализации списка");
        return -1;
    }

     AppendData appendData = { StudentList, NULL };

    appendData.student = InitStudent((void* []) { "Elena", "Sukhova", "15", "ISP-111", "23", "2", "2", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Timur", "Sharipov", "55", "SIS-234", "14", "4", "4", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Evgeniy", "Skufov", "44", "KS-543", "17", "5", "3", "3" });
    Append(&appendData);
    UpData upData = {StudentList, 0 };

    for (int i = 0; i < StudentList->size; i++  ){
        upData.index = i;
        Up(&upData);
    }

    PrintList(StudentList);

    if (saveFile("students.bin", StudentList) != 0) {
        FreeList(StudentList);
        return -1;
    }

    List* new_list = loadFile("students.bin");
    if (new_list == NULL) {
        FreeList(StudentList);
        return -1;
    }

    FreeList(StudentList);
    FreeList(new_list);

    system("pause");
    return 0;
}