#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap arr[i] and arr[min_index]
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Selection Sort: Unsorted array: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Selection Sort: Sorted array: ");
    printArray(arr, n);

    free(arr);
    return 0;
}
