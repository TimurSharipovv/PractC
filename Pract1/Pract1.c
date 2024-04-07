#include <locale.h>
#include <time.h>
#include <stdio.h>

int GradesArray() {
    int numGrades;
    printf("������� ���������� ������: ");
    scanf("%d", &numGrades);

    if (numGrades <= 0) {
        printf("���������� ������ ������ ���� ������������� ������.\n");
        return 1;
    }

    int* grades = (int*)malloc(numGrades * sizeof(int));
    if (grades == NULL) {
        printf("������ ��������� ������ ��� ������.\n");
        return 1;
    }

    fillArrayWithRandomGrades(grades, numGrades);

    printf("��������������� ������:\n");
    printGrades(grades, numGrades);

    free(grades);

    return 0;
}

int fillArrayWithRandomGrades(int* grades, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; ++i) {
        grades[i] = rand() % 4 + 2;
    }
}


int printGrades(const int* grades, int count) {
    for (int i = 0; i < count; ++i) {
        printf("������ %d: %d\n", i + 1, grades[i]);
    }
}

/////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRAY_SIZE = 7;
const int MIN_GRADE = 2;
const int MAX_GRADE = 5;
const int SCHOLARSHIP_THRESHOLD = 4;

void fillArrayWithRandomGrades(int* grades, int size) {
    for (int i = 0; i < size; i++) {
        grades[i] = MIN_GRADE + rand() % (MAX_GRADE - MIN_GRADE + 1);
    }
}

double calculateAverage(int* grades, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return (double)sum / size;
}

int main() {
    int grades[ARRAY_SIZE];
    double average;

    // ������������� ���������� ��������� �����
    srand((unsigned int)time(NULL));

    // ���������� ������� ���������� ��������
    fillArrayWithRandomGrades(grades, ARRAY_SIZE);

    // ���������� �������� ���������������
    average = calculateAverage(grades, ARRAY_SIZE);

    // ����� ������ � �������� ���������������
    printf("Grades: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", grades[i]);
    }
    printf("\nAverage: %.2f\n", average);

    // �������� �� ���������
    if (average >= SCHOLARSHIP_THRESHOLD) {
        printf("The student is eligible for a scholarship.\n");
    }
    else {
        printf("The student is not eligible for a scholarship.\n");
    }

    return 0;
}