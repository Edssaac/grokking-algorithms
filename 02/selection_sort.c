#include <stdio.h>

void printArray(int[], int);
void selectionSort(int[], int);

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array antes da ordenacao:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nArray depois da ordenacao:\n");
    printArray(arr, n);

    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Percorre o array
    for (i=0; i<n-1; i++) {
        // Encontra o menor elemento no restante do array:
        min_idx = i;

        for (j=i+1; j<n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor elemento com o primeiro elemento não ordenado:
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
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
