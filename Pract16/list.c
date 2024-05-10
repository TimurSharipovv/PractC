#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "list.h"
#include "student.c"

void* InitList(void* args) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        perror("Ошибка при выделении памяти для списка");
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
        perror("Ошибка при выделении памяти для нового узла");
        return NULL;
    }
    newNode->student = student;
    newNode->next = NULL;

    if (list->size == 0) {
        list->head = newNode;
        list->tail = list->head;
    } else {
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
    } else {
        fprintf(stderr, "Индекс вне диапазона: %d\n", index);
        errno = ERANGE;
        return NULL;
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