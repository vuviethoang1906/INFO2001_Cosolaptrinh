#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    return executionTime;
}
int main() {
    int arr[] = {19, 6,  2005};
    int n = sizeof(arr) / sizeof(arr[0]);
    double bubbleSortTime = measureTime(bubbleSort, arr, n);
    double selectionSortTime = measureTime(selectionSort, arr, n);
    printf("Mang duoc sap xep bang Bubble Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Thoi gian thuc thi Bubble Sort: %.2f giay\n", bubbleSortTime);
    printf("Mang duoc sap xep bang Selection Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Thoi gian thuc thi Selection Sort: %.2f giay\n", selectionSortTime);
    return 0;
}