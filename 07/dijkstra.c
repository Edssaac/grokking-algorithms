#include <stdio.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX_VERTICES 100

// Estrutura para representar um grafo
typedef struct {
    int numVertices;
    int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];
} Grafo;

// Função para inicializar o grafo
void inicializarGrafo(Grafo* grafo, int numVertices) {
    grafo->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            grafo->matrizAdjacencia[i][j] = (i == j) ? 0 : INFINITY;
        }
    }
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    grafo->matrizAdjacencia[origem][destino] = peso;
    grafo->matrizAdjacencia[destino][origem] = peso;
}

// Função para encontrar o índice do vértice com a distância mínima
int encontrarVerticeMinimo(int distancias[], bool visitados[], int numVertices) {
    int minimo = INFINITY;
    int indiceMinimo;

    for (int v = 0; v < numVertices; v++) {
        if (!visitados[v] && distancias[v] <= minimo) {
            minimo = distancias[v];
            indiceMinimo = v;
        }
    }

    return indiceMinimo;
}

// Função para exibir o caminho mais curto a partir da origem para cada vértice
void exibirCaminhoMaisCurto(int distancias[], int numVertices, int origem) {
    printf("Caminho mais curto a partir do vertice %d:\n", origem);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertice %d -> Vertice %d | Distancia: %d\n", origem, i, distancias[i]);
    }
}

// Algoritmo de Dijkstra
void dijkstra(Grafo* grafo, int origem) {
    int distancias[MAX_VERTICES];
    bool visitados[MAX_VERTICES];

    for (int i = 0; i < grafo->numVertices; i++) {
        distancias[i] = INFINITY;
        visitados[i] = false;
    }

    distancias[origem] = 0;

    for (int count = 0; count < grafo->numVertices - 1; count++) {
        int u = encontrarVerticeMinimo(distancias, visitados, grafo->numVertices);
        visitados[u] = true;

        for (int v = 0; v < grafo->numVertices; v++) {
            if (!visitados[v] && grafo->matrizAdjacencia[u][v] != INFINITY &&
                distancias[u] + grafo->matrizAdjacencia[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + grafo->matrizAdjacencia[u][v];
            }
        }
    }

    exibirCaminhoMaisCurto(distancias, grafo->numVertices, origem);
}

int main() {
    Grafo grafo;
    int numVertices, numArestas;
    int origem, destino, peso;

    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &numVertices);

    inicializarGrafo(&grafo, numVertices);

    printf("Digite o numero de arestas do grafo: ");
    scanf("%d", &numArestas);

    for (int i = 0; i < numArestas; i++) {
        printf("Digite a origem, destino e peso da aresta %d: ", i + 1);
        scanf("%d %d %d", &origem, &destino, &peso);
        adicionarAresta(&grafo, origem, destino, peso);
    }

    printf("Digite o vertice de origem: ");
    scanf("%d", &origem);

    dijkstra(&grafo, origem);

    return 0;
}
