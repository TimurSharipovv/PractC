#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <malloc.h>

void fillArrayWithRandomNumbers(int* array, int size);
int* filterPositiveNumbers(const int* sourceArray, int size, int* count);
void printArray(const int* array, int size);
int DinamicArray();
void fillArrayWithRandomGrades(int* Grades, int CountGrades);
void printGrades(const int* Grades, int CountGrades);
int GradesArray();
int* createMatrixWithRandomNumbers(int size, int min, int max);
int countZeros(const int* array, int size);
void printMatrix(const int* array, int size);
int MatrixMas();
void fillArraypr3WithRandomNumbers(int rows, int cols, int** array);
void printArraypr3(int rows, int cols, int** array);
void replaceEvenNumbersWithZero(int rows, int cols, int** array);
double divide(double a, double b);
double multiply(double a, double b);
double sum(double a, double b);
double substract(double a, double b);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int CountGrades = 7;

    int (*ExecuteDimnamicMas)() = DinamicArray;
    ExecuteDimnamicMas();

    int (*ExecuteGradesArray)() = GradesArray;
    ExecuteGradesArray();

    int (*ExecuteMatrixArray)() = MatrixMas;
    ExecuteMatrixArray();

    double a = 4, b = 9;

    double(*calc[4])(double, double) = { sum, multiply, divide, substract };
    printf("Ваш результат:\n");
    for (int i = 0; i < 4; i++)
    {

        printf("%lf\n", calc[i](a, b));
    }


    return 0;
}

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


void fillArrayWithRandomGrades(int* Grades, int CountGrades) {
    srand(time(NULL));
    for (int i = 0; i < CountGrades; i++) {
        Grades[i] = rand() % 4 + 2;
    }
}


void printGrades(const int* Grades, int CountGrades) {
    for (int i = 0; i < CountGrades; i++) {
        printf("Оценка %d: %d\n", i + 1, Grades[i]);
    }
}

int GradesArray() {
    int numGrades;
    printf("Введите количество оценок: ");
    scanf("%d", &numGrades);

    if (numGrades <= 0) {
        printf("Количество оценок должно быть положительным числом.\n");
        return 1;
    }

    int* grades = (int*)malloc(numGrades * sizeof(int));
    if (grades == NULL) {
        printf("Ошибка выделения памяти для оценок.\n");
        return 1;
    }

    fillArrayWithRandomGrades(grades, numGrades);

    printf("Сгенерированные оценки:\n");
    printGrades(grades, numGrades);

    free(grades);

    return 0;
}

int* createMatrixWithRandomNumbers(int size, int min, int max) {
    int* matrix = (int*)malloc(size * sizeof(int));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти для массива.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        matrix[i] = rand() % (max - min + 1) + min;
    }

    return matrix;
}

int countZeros(const int* array, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            count++;
        }
    }
    return count;
}

void printMatrix(const int* array, int size) {
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
    printMatrix(array, arraySize);

    int zeroCount = countZeros(array, arraySize);
    printf("Количество нулей в массиве: %d\n", zeroCount);


    free(array);

    return 0;
}

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

double divide(double a, double b)
{
    return a / b;
}

double multiply(double a, double b)
{
    return a * b;
}

double sum(double a, double b)
{
    return a + b;
}

double substract(double a, double b)
{
    return a - b;
}
