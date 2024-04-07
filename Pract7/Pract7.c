#include <locale.h>
#include <time.h>
#include <stdio.h>

int countZeros(int arr[], int n, int index) {
    if (index >= n)
        return 0;
    return (arr[index] == 0) + countZeros(arr, n, index + 1);
}


void printArrayRecursively(int arr[], int size, int index) {
    if (index >= size) {
        return 0;
    }

    printf("%d ", arr[index]);
    printArrayRecursively(arr, size, index - 1);
}

int main() {
    int arr[] = { 0, 1, 2, 0, 3, 0, 5, 6, 0, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printArrayRecursively(arr, size, 0);

    return 0;
}


int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int arr[] = { 0, 1, 2, 0, 3, 0, 5, 6, 0, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Количество нулей в массиве: %d\n", countZeros(arr, n, 0));
    return 0;
}
