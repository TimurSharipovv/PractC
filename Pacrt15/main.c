#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "list.c"
#include <errno.h>

int saveFile(char* path, List* StudentList)
{
    FILE* file;
    file = fopen(path, "wb");
    if (file == NULL){
        printf("errno %d\n", errno);
    }
    fwrite(StudentList, sizeof(List), 1, file);
    fclose(file);
    return 0;
}

List* loadFile(char* path)
{
    List* list = malloc(sizeof(List));
    FILE* file;
    file = fopen(path, "rb");
    fread(list, sizeof(List), 1, file);
    fclose(file);
    return list;
}

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList(NULL);
    if (StudentList == NULL) {
        return 0;
    }
    
     AppendData appendData = { StudentList, NULL };

    appendData.student = InitStudent((void* []) { "Elena", "Sukhova", "15", "ISP-111", "23", "2", "2", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Timur", "Sharipov", "55", "SIS-234", "14", "4", "4", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Evgeniy", "Skufov", "44", "KS-543", "17", "5", "3", "3" });
    Append(&appendData);

    UpData upData = { StudentList, 0 };

    PrintList(StudentList);
    FreeList(StudentList);
    saveFile("students.bin",StudentList);

    List* new_list = loadFile("students.bin");
  for (int i = 0; i < StudentList->size; i++) {
        upData.index = i;
        Up(&upData);
    }

    system("pause");
    return 0;
}

