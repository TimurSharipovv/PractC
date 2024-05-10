#ifndef LIST_H
#define LIST_H

#include "node.h" 

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

#define SAFE_FREE(ptr) do { \
    free(ptr); \
    ptr = NULL; \
} while(0)

#endif