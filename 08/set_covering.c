#include <stdio.h>
#include <stdbool.h>

#define MAX_SETS 100
#define MAX_ELEMENTS 100

// Função para encontrar o próximo conjunto a ser selecionado
int findNextSet(bool covered[], int num_elements, int num_sets, bool sets[MAX_SETS][MAX_ELEMENTS]) {
    int max_uncovered = 0;
    int next_set = -1;

    for (int i = 0; i < num_sets; i++) {
        if (!covered[i]) {
            int uncovered_elements = 0;

            for (int j = 0; j < num_elements; j++) {
                if (sets[i][j] && !covered[j]) {
                    uncovered_elements++;
                }
            }

            if (uncovered_elements > max_uncovered) {
                max_uncovered = uncovered_elements;
                next_set = i;
            }
        }
    }

    return next_set;
}

// Função para resolver o problema Set Covering
void solveSetCovering(int num_elements, int num_sets, bool sets[MAX_SETS][MAX_ELEMENTS]) {
    bool covered[MAX_ELEMENTS] = {false};
    int num_covered = 0;

    while (num_covered < num_elements) {
        int next_set = findNextSet(covered, num_elements, num_sets, sets);

        if (next_set == -1) {
            printf("Nao foi possivel encontrar uma solucao de cobertura.\n");
            return;
        }

        printf("Selecionado conjunto %d:", next_set);
        for (int i = 0; i < num_elements; i++) {
            if (sets[next_set][i] && !covered[i]) {
                covered[i] = true;
                num_covered++;
                printf(" %d", i);
            }
        }
        printf("\n");
    }
}

int main() {
    int num_elements, num_sets;
    bool sets[MAX_SETS][MAX_ELEMENTS];

    printf("Digite o numero de elementos: ");
    scanf("%d", &num_elements);

    printf("Digite o numero de conjuntos: ");
    scanf("%d", &num_sets);

    printf("Digite os elementos dos conjuntos (1 para incluir, 0 para nao incluir):\n");
    for (int i = 0; i < num_sets; i++) {
        for (int j = 0; j < num_elements; j++) {
            scanf("%d", &sets[i][j]);
        }
    }

    solveSetCovering(num_elements, num_sets, sets);

    return 0;
}

/*
6
4
0 1 0 1 0 0
1 0 1 0 0 0
0 0 0 1 1 0
0 1 0 0 0 1
*/
