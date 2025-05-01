#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, key, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = linearSearch(arr, n, key);
    if (index != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, index);
    } else {
        printf("Linear Search: Element %d not found\n", key);
    }

    free(arr);
    return 0;
}
