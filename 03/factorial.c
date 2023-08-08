#include <stdio.h>

int factorial(int);

int main(void) {
    printf("F(5): %d\n", factorial(5));
    printf("F(7): %d\n", factorial(7));
    printf("F(9): %d\n", factorial(9));
    printf("F(11): %d\n", factorial(11));

    return 0;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return (n * factorial(n-1));
}
