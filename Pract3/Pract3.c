#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>


void fillArraypr3WithRandomNumbers(int rows, int cols, int** array) {
    srand(time(NULL));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 100;
        }
    }
}

void printArraypr3(int rows, int cols, int** array) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void replaceEvenNumbersWithZero(int rows, int cols, int** array) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] % 2 == 0) {
                array[i][j] = 0;
            }
        }
    }
}

int pr3() {
    srand(time(NULL));
    int rows = rand() % 9 + 2;
    int cols = rand() % 9 + 2;

    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }

    fillArrayWithRandomNumbers(rows, cols, array);

    printf("Исходный массив:\n");
    printArray(rows, cols, array);

    replaceEvenNumbersWithZero(rows, cols, array);

    printf("\nМассив после замены четных чисел на 0:\n");
    printArray(rows, cols, array);

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}