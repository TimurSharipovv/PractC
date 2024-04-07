#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    struct Student* student;
    struct Node* next;
} Node;

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

typedef struct List {
    Node* head;
    Node* tail;
    int size;
} List;

typedef struct AppendData {
    List* list;
    Student* student;
} AppendData;

typedef struct UpData {
    List* list;
    int index;
} UpData;

void* Append(void* data) {
    AppendData* appendData = (AppendData*)data;
    List* list = appendData->list;
    Student* student = appendData->student;

    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->student = student;
    newNode->next = NULL;

    if (list->size == 0) {
        list->head = newNode;
        list->tail = list->head;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
    return list;
}

void* Up(void* data) {
    UpData* upData = (UpData*)data;
    List* list = upData->list;
    int index = upData->index;

    if (index >= 0 && index < list->size) {
        Node* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        if (current->student->physicGrade < 5) {
            current->student->physicGrade += 2;
            if (current->student->physicGrade > 5) {
                current->student->physicGrade = 5;
            }
        }
    }
    return list;
}

void* InitList(void* args) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

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

void PrintList(void* list) {
    List* LIST = (List*)list;
    Node* current = LIST->head;
    while (current != NULL) {
        printf("%s - %d\n", current->student->name, current->student->physicGrade);
        current = current->next;
    }
}

void FreeList(void* list) {
    List* LIST = (List*)list;
    Node* current = LIST->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student);
        free(temp);
    }
    free(LIST);
}

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