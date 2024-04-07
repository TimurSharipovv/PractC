#include <stdio.h>
#include <locale.h>
#include "list14.h"

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList(NULL);
    if (StudentList == NULL) {
        return 1;
    }

    // Загрузка данных из файла
    LoadFromFile(StudentList, "students.txt");

    // ... ваш код для работы со списком ...

    // Сохранение данных в файл
    SaveToFile(StudentList, "students.txt");

    FreeList(StudentList);
    return 0;
}