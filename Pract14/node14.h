#ifndef NODE_H
#define NODE_H

#include "student14.h" 

typedef struct Node {
    struct Student* student;
    struct Node* next;
} Node;

#endif