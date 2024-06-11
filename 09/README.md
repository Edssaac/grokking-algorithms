O algoritmo "longest common subsequence" é usado para encontrar o comprimento da maior subsequência comum entre duas 
sequências dadas, X e Y. Uma subsequência é uma sequência que pode ser obtida a partir de outra sequência eliminando 
alguns elementos, sem alterar a ordem dos elementos restantes. 

```c
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
```

Vamos analisar o código:

```c
int max(int a, int b) {
    return (a > b) ? a : b;
}
```
Esta função `max` simplesmente retorna o maior valor entre dois números.

```c
int longestCommonSubsequence(char *X, char *Y, int m, int n) {
    int lcs[m + 1][n + 1];
```
Aqui, é criada uma matriz `lcs` de dimensões `(m + 1) x (n + 1)`. <br>
Esta matriz será usada para armazenar os comprimentos das subsequências comuns encontradas até o momento.

```c
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
```
Esses dois loops aninhados iteram sobre todas as combinações de índices `i` e `j` da matriz `lcs`. <br>
Para cada combinação, o algoritmo faz o seguinte:
- Se `i` ou `j` é zero, isso significa que uma das sequências é vazia, então `lcs[i][j]` é definido como zero.
- Se os caracteres em `X[i-1]` e `Y[j-1]` são iguais, isso significa que encontramos um caractere comum, então `lcs[i][j]` é definido como `lcs[i-1][j-1] + 1`.
- Se os caracteres não são iguais, então `lcs[i][j]` é definido como o máximo entre o comprimento da subsequência comum excluindo o último caractere de `X` e o último caractere de `Y`, ou seja, `max(lcs[i-1][j], lcs[i][j-1])`.

```c
    return lcs[m][n];
```
Finalmente, o valor armazenado em `lcs[m][n]` é retornado, que representa o comprimento da maior subsequência comum entre `X` e `Y`.
