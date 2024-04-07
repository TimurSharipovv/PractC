#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<malloc.h>
#include<time.h>


void fillArrayWithRandomNumbers(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 20 - 9;
    }
}

int* filterPositiveNumbers(const int* sourceArray, int size, int* count) {
    int* destinationArray = NULL;
    *count = 0;

    for (int i = 0; i < size; i++) {
        if (sourceArray[i] > 0) {
            destinationArray = (int*)realloc(destinationArray, (*count + 1) * sizeof(int));
            if (destinationArray == NULL) {
                perror("Error: memory allocation failed");
                exit(EXIT_FAILURE);
            }
            destinationArray[*count] = sourceArray[i];
            (*count)++;
        }
    }

    return destinationArray;
}

void printArray(const int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

int DinamicArray() {
    setlocale(LC_ALL, "Rus");
    const int SIZE = 10;
    int* firstmas = (int*)malloc(SIZE * sizeof(int));
    int* secondmas = NULL;
    int count;

    if (firstmas == NULL) {
        perror("Error: memory allocation failed");
        return EXIT_FAILURE;
    }

    fillArrayWithRandomNumbers(firstmas, SIZE);
    printArray(firstmas, SIZE);

    secondmas = filterPositiveNumbers(firstmas, SIZE, &count);
    printf("\nПоложительные числа:\n");
    printArray(secondmas, count);

    free(firstmas);
    free(secondmas);
    return 0;
}