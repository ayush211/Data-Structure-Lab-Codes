#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // To avoid overflow
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, key, i;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements of the sorted array in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, index);
    } else {
        printf("Binary Search: Element %d not found\n", key);
    }

    free(arr);
    return 0;
}
