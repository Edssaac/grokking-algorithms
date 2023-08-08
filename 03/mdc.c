#include <stdio.h>

int mdc(int, int);

int main(void) {
    printf("MDC(15, 9)      = %d\n", mdc(15, 9));
    printf("MDC(180, 150)   = %d\n", mdc(180, 150));
    printf("MDC(60, 28)     = %d\n", mdc(60, 28));

    return 0;
}

int mdc(int a, int b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        return mdc(b, (a-b));
    }

    return mdc(a, (b-a));
}
