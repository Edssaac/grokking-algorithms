#include <stdio.h>

void printArray(int[], int);
void selectionSort(int[], int);

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nAfter:\n");
    printArray(arr, n);

    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, min_index, temp;

    for (i=0; i<n-1; i++) {
        min_index = i;

        for (j=i+1; j<n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;

    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
