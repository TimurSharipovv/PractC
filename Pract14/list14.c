#include <stdlib.h>
#include <stdio.h>
#include "list14.h"

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

void SaveToFile(List* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла для записи");
        return;
    }

    Node* current = list->head;
    while (current != NULL) {
        fprintf(file, "%s %s %s %s %d %d %d %d\n",
            current->student->name,
            current->student->surname,
            current->student->gender,
            current->student->group,
            current->student->age,
            current->student->mathGrade,
            current->student->physicGrade,
            current->student->chemistryGrade
        );
        current = current->next;
    }

    fclose(file);
}

void LoadFromFile(List* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла для чтения");
        return;
    }

    char name[100], surname[100], gender[100], group[100];
    int age, mathGrade, physicGrade, chemistryGrade;

    while (fscanf(file, "%s %s %s %s %d %d %d %d",
        name, surname, gender, group,
        &age, &mathGrade, &physicGrade, &chemistryGrade) == 8) {
        AppendData appendData = { list, NULL };
        appendData.student = InitStudent((void* []) {
            name, surname, gender, group,
                age, mathGrade, physicGrade, chemistryGrade
        });
        Append(&appendData);
    }

    fclose(file);
}