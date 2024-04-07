#include <stdio.h>
#include <locale.h>
#include "list14.h"

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList(NULL);
    if (StudentList == NULL) {
        return 1;
    }

    // �������� ������ �� �����
    LoadFromFile(StudentList, "students.txt");

    // ... ��� ��� ��� ������ �� ������� ...

    // ���������� ������ � ����
    SaveToFile(StudentList, "students.txt");

    FreeList(StudentList);
    return 0;
}