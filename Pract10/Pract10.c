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

void Append(List* list, Student* student) {
    Node* newNode = malloc(sizeof(Node));
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
}

void Up(List* list, int index) {
    if (index >= 0 && index < list->size) {
        Node* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        if (current->student->physicGrade + 2 <= 5) {
            current->student->physicGrade += 2;
        }
        else {
            current->student->physicGrade = 5;
        }
    }
}

List* InitList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

Student* InitStudent(int age, char* name, char* surname, char* gender, char* group, int mathGrade, int physicGrade, int chemistryGrade) {
    Student* student = malloc(sizeof(Student));
    student->name = name;
    student->surname = surname;
    student->gender = gender;
    student->group = group;
    student->mathGrade = mathGrade;
    student->physicGrade = physicGrade;
    student->chemistryGrade = chemistryGrade;
    student->age = age;
    return student;
}

void PrintList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%s - %d\n", current->student->name, current->student->physicGrade);
        current = current->next;
    }
}

void FreeList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student);
        free(temp);
    }
    free(list);
}

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList();
    Append(StudentList, InitStudent(23, "Ivan", "Tfgd", "муж", "ghgjf4", 4, 2, 3));
    Append(StudentList, InitStudent(14, "Vaho", "Tfgd", "муж", "ghgjf4", 4, 4, 3));
    Append(StudentList, InitStudent(17, "Timur", "Tfgd", "муж", "ghgjf4", 4, 3, 3));
    for (int i = 0; i < StudentList->size; i++) {
        Up(StudentList, i);
    }
    PrintList(StudentList);
    FreeList(StudentList);
    return 0;
}