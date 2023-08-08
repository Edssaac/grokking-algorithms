#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um n� em uma lista de adjac�ncias
struct Node {
    int data;
    struct Node* next;
};

// Estrutura para representar um grafo com uma lista de adjac�ncias
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Fun��o para criar um novo n� com um dado v�rtice
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para criar um grafo com um n�mero espec�fico de v�rtices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node*)malloc(numVertices * sizeof(struct Node));

    int i;
    for (i = 0; i < numVertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Fun��o para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Como o grafo � n�o-direcionado, tamb�m precisamos adicionar a aresta no sentido inverso
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Fun��o para realizar a busca em largura (BFS) no grafo
void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int i;

    // Inicializa o array de visitados como falso (0)
    for (i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    // Cria uma fila para armazenar os v�rtices a serem visitados
    struct Node* queue = createNode(startVertex);
    visited[startVertex] = 1;

    while (queue != NULL) {
        int currentVertex = queue->data;
        printf("Visitando vertice %d\n", currentVertex);

        // Percorre todos os v�rtices adjacentes e os adiciona � fila se ainda n�o foram visitados
        struct Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue->next = createNode(adjVertex);
                queue = queue->next;
            }
            temp = temp->next;
        }

        // Move para o pr�ximo n� da fila
        struct Node* oldNode = queue;
        queue = queue->next;
        free(oldNode);
    }

    free(visited);
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("Realizando a busca em largura (BFS) a partir do vertice 0:\n");
    BFS(graph, 0);

    return 0;
}
