#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

typedef struct {
    char chave[50];
    int valor;
} Elemento;

typedef struct {
    Elemento* elementos[TAMANHO_TABELA];
} TabelaHash;

TabelaHash* criarTabelaHash() {
    TabelaHash* tabela = (TabelaHash*) malloc(sizeof(TabelaHash));
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->elementos[i] = NULL;
    }
    return tabela;
}

int calcularIndice(char* chave) {
    int soma = 0;
    for (int i = 0; i < strlen(chave); i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

void inserir(TabelaHash* tabela, char* chave, int valor) {
    int indice = calcularIndice(chave);

    Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));
    strcpy(elemento->chave, chave);
    elemento->valor = valor;

    tabela->elementos[indice] = elemento;
}

int buscar(TabelaHash* tabela, char* chave) {
    int indice = calcularIndice(chave);

    Elemento* elemento = tabela->elementos[indice];

    if (elemento != NULL && strcmp(elemento->chave, chave) == 0) {
        return elemento->valor;
    }

    return -1; // Valor não encontrado
}

void remover(TabelaHash* tabela, char* chave) {
    int indice = calcularIndice(chave);

    Elemento* elemento = tabela->elementos[indice];

    if (elemento != NULL && strcmp(elemento->chave, chave) == 0) {
        free(elemento);
        tabela->elementos[indice] = NULL;
    }
}

void liberarTabelaHash(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela->elementos[i] != NULL) {
            free(tabela->elementos[i]);
        }
    }
    free(tabela);
}

int main() {
    TabelaHash* tabela = criarTabelaHash();

    inserir(tabela, "chave1", 10);
    inserir(tabela, "chave2", 20);
    inserir(tabela, "chave3", 30);

    printf("%d\n", buscar(tabela, "chave2")); // Saída: 20

    remover(tabela, "chave1");

    printf("%d\n", buscar(tabela, "chave1")); // Saída: -1

    liberarTabelaHash(tabela);

    return 0;
}
