#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct TreeNode {
    Student* student;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
    TreeNode* (*createTreeNode)(Student*);
    void (*insertStudent)(struct Tree*, Student*);
    void (*increasePhysicGrade)(TreeNode*, int, int*);
    void (*printTreeInOrder)(TreeNode*);
    void (*freeTree)(TreeNode*);
} Tree;

TreeNode* createTreeNode(Student* student) {
    TreeNode* newNode = malloc(sizeof(TreeNode));
    newNode->student = student;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree* createTree() {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->createTreeNode = createTreeNode;
    tree->insertStudent = insertStudent;
    tree->increasePhysicGrade = increasePhysicGrade;
    tree->printTreeInOrder = printTreeInOrder;
    tree->freeTree = freeTree;
    return tree;
}

void insertStudent(Tree* tree, Student* student) {
    TreeNode* newNode = tree->createTreeNode(student);
    if (tree->root == NULL) {
        tree->root = newNode;
    }
    else {
        TreeNode* current = tree->root;
        TreeNode* parent = NULL;
        while (current != NULL) {
            parent = current;
            if (strcmp(student->name, current->student->name) < 0) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        if (strcmp(student->name, parent->student->name) < 0) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }
    }
}

void increasePhysicGrade(TreeNode* node, int index, int* currentIndex) {
    if (node != NULL) {
        increasePhysicGrade(node->left, index, currentIndex);
        if (*currentIndex == index) {
            if (node->student->physicGrade + 2 <= 5) {
                node->student->physicGrade += 2;
            }
            else {
                node->student->physicGrade = 5;
            }
        }
        (*currentIndex)++;
        increasePhysicGrade(node->right, index, currentIndex);
    }
}

void printTreeInOrder(TreeNode* node) {
    if (node != NULL) {
        printTreeInOrder(node->left);
        printf("%s - %d\n", node->student->name, node->student->physicGrade);
        printTreeInOrder(node->right);
    }
}

void freeTree(TreeNode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node->student);
        free(node);
    }
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

int main() {
    Tree* studentTree = createTree();
    studentTree->insertStudent(studentTree, InitStudent(23, "Ivan", "Tfgd", "муж", "ghgjf4", 4, 2, 3));
    studentTree->insertStudent(studentTree, InitStudent(14, "Vaho", "Tfgd", "муж", "ghgjf4", 4, 4, 3));
    studentTree->insertStudent(studentTree, InitStudent(17, "Timur", "Tfgd", "муж", "ghgjf4", 4, 3, 3));
    int index = 0;
    studentTree->increasePhysicGrade(studentTree->root, index, &index);
    studentTree->printTreeInOrder(studentTree->root);
    studentTree->freeTree(studentTree->root);
    free(studentTree);
    return 0;
}