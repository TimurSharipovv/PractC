#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������� ��� �������� ������� � ���������� �������
int* createMatrixWithRandomNumbers(int size, int min, int max) {
    int* matrix = (int*)malloc(size * sizeof(int));
    if (matrix == NULL) {
        printf("������ ��������� ������ ��� �������.\n");
        exit(1);
    }

    srand(time(NULL)); // ������������� ���������� ��������� �����
    for (int i = 0; i < size; ++i) {
        matrix[i] = rand() % (max - min + 1) + min;
    }

    return matrix;
}

// ������� ��� �������� ���������� ����� � �������
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

    printf("������ �����:\n");
    printArray(array, arraySize);

    int zeroCount = countZeros(array, arraySize);
    printf("���������� ����� � �������: %d\n", zeroCount);


    free(array);

    return 0;
}