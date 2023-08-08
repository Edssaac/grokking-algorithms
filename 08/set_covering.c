#include <stdio.h>
#include <stdbool.h>

#define MAX_SETS 100
#define MAX_ELEMENTS 100

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

void solveSetCovering(int num_elements, int num_sets, bool sets[MAX_SETS][MAX_ELEMENTS]) {
    bool covered[MAX_ELEMENTS] = {false};
    int num_covered = 0;

    while (num_covered < num_elements) {
        int next_set = findNextSet(covered, num_elements, num_sets, sets);

        if (next_set == -1) {
            printf("Could not find a coverage solution.\n");

            return;
        }

        printf("Selected Set %d:", next_set);

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

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    printf("Enter the number of sets: ");
    scanf("%d", &num_sets);

    printf("Enter the elements of the sets (1 to include, 0 to not include):\n");

    for (int i = 0; i < num_sets; i++) {
        for (int j = 0; j < num_elements; j++) {
            scanf("%d", &sets[i][j]);
        }
    }

    solveSetCovering(num_elements, num_sets, sets);

    return 0;
}