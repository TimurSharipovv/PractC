#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для создания массива с случайными числами
int* createMatrixWithRandomNumbers(int size, int min, int max) {
    int* matrix = (int*)malloc(size * sizeof(int));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти для массива.\n");
        exit(1);
    }

    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        matrix[i] = rand() % (max - min + 1) + min;
    }

    return matrix;
}

// Функция для подсчета количества нулей в массиве
int countZeros(const int* array, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            count++;
        }
    }
    return count;
}

void printArray(const int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int MatrixMas() {
    int arraySize = 10;
    int rangeMin = 0;
    int rangeMax = 10;

    int* array = createMatrixWithRandomNumbers(arraySize, rangeMin, rangeMax);

    printf("Массив чисел:\n");
    printArray(array, arraySize);

    int zeroCount = countZeros(array, arraySize);
    printf("Количество нулей в массиве: %d\n", zeroCount);


    free(array);

    return 0;
}