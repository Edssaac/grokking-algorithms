#include <stdio.h>

int fatorial(int);

int main(void) {
    printf("Fatorial de 5: %d\n", fatorial(5));
    printf("Fatorial de 7: %d\n", fatorial(7));
    printf("Fatorial de 9: %d\n", fatorial(9));
    printf("Fatorial de 11: %d\n", fatorial(11));

    return 0;
}

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return (n * fatorial(n-1));
}
