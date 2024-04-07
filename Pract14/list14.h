#ifndef LIST_H
#define LIST_H

#include "node14.h"

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

void* InitList(void* args);
void* Append(void* data);
void* Up(void* data);
void PrintList(void* list);
void FreeList(void* list);
void SaveToFile(List* list, const char* filename);
void LoadFromFile(List* list, const char* filename);

#endif