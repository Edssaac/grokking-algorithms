#include <stdio.h>

int sum(int*, int);
int recursive_sum(int*, int, int);

int main(void) {
    int values[4] = {1, 2, 3, 4};

    printf("Sum: %d\n", sum(values, 4));
    printf("Recursive Sum: %d\n", recursive_sum(values, 4, 0));

    return 0;
}

int sum(int *arr, int size) {
    int total = 0;

    for (int i=0; i<size; i++) {
        total += arr[i];
    }

    return total;
}

int recursive_sum(int *arr, int size, int index) {
    if (index == size) {
        return 0;
    }

    return arr[index] + recursive_sum(arr, size, index+1);
}
