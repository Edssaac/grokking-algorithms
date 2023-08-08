#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char *X, char *Y, int m, int n) {
    int lcs[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    return lcs[m][n];
}

int main() {
    char X[] = "FISH";
    char Y[] = "FOSH";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of the Greatest Common Subsequence: %d\n", longestCommonSubsequence(X, Y, m, n));

    return 0;
}
