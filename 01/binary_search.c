#include <stdio.h>

int pesquisa_binaria(int[], int);
int pesquisa_binaria_recursiva(int[], int, int, int);

int main() {

    int lista_ordenada[] = {0, 5, 7, 24, 45, 59, 82};
    
    printf("%d\n", pesquisa_binaria(lista_ordenada, 7));
    printf("%d\n", pesquisa_binaria(lista_ordenada, 59));
    printf("%d\n", pesquisa_binaria(lista_ordenada, 99));
    
    puts("-------\n");

    int baixo = 0;
    int alto = sizeof(&lista_ordenada) - 1;
    
    printf("%d\n", pesquisa_binaria_recursiva(lista_ordenada, 7, baixo, alto));
    printf("%d\n", pesquisa_binaria_recursiva(lista_ordenada, 59, baixo, alto));
    printf("%d\n", pesquisa_binaria_recursiva(lista_ordenada, 99, baixo, alto));
    
    return 0;
}

int pesquisa_binaria(int lista[], int item) {

    int baixo = 0;
    int alto = sizeof(&lista) - 1;
    int meio, chute;
    
    while (baixo <= alto) {
        meio = (baixo + alto) / 2;
        chute = lista[meio];
        
        if (chute == item) {
            return meio;
        }
       
        if (chute > item) {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }
    
    return -1;
}

int pesquisa_binaria_recursiva(int lista[], int item, int baixo, int alto) {

    if (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int chute = lista[meio];
        
        if (chute == item) {
            return meio;
        }
        
        if (chute > item) {
            return pesquisa_binaria_recursiva(lista, item, baixo, (meio-1));
        }
            
        return pesquisa_binaria_recursiva(lista, item, (meio+1), alto);
    }

    return -1;
}