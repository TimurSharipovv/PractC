#include <stdio.h>
#include <locale.h>
#include "list.h"

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList(NULL);
    if (StudentList == NULL) {
        return 1;
    }

    AppendData appendData = { StudentList, NULL };

    appendData.student = InitStudent((void* []) { "Ivan", "Tfgd", "муж", "ghgjf4", "23", "4", "2", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Vaho", "Tfgd", "муж", "ghgjf4", "14", "4", "4", "3" });
    Append(&appendData);

    appendData.student = InitStudent((void* []) { "Timur", "Tfgd", "муж", "ghgjf4", "17", "4", "3", "3" });
    Append(&appendData);

    UpData upData = { StudentList, 0 };

    for (int i = 0; i < StudentList->size; i++) {
        upData.index = i;
        Up(&upData);
    }

    PrintList(StudentList);
    FreeList(StudentList);
    return 0;
}