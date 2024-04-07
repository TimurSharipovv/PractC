#include <stdlib.h>
#include <stdio.h>
#include "list.h"

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
    List* l = (List*)list;
    Node* current = l->head;
    while (current != NULL) {
        Node* next = current->next;
        SAFE_FREE(current);
        current = next;
    }
    SAFE_FREE(l);
}