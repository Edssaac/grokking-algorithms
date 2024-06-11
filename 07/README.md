```c
#define INFINITY 9999
#define MAX_VERTICES 100

typedef struct {
    int numberVertices;
    int adjacentList[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph* graph, int numberVertices) {
    graph->numberVertices = numberVertices;

    for (int i = 0; i < numberVertices; i++) {
        for (int j = 0; j < numberVertices; j++) {
            graph->adjacentList[i][j] = (i == j) ? 0 : INFINITY;
        }
    }
}

void addEdge(Graph* graph, int origin, int destiny, int weight) {
    graph->adjacentList[origin][destiny] = weight;
    graph->adjacentList[destiny][origin] = weight;
}

int findMinVertex(int distances[], bool visited[], int numberVertices) {
    int min = INFINITY;
    int minIndex;

    for (int v = 0; v < numberVertices; v++) {
        if (!visited[v] && distances[v] <= min) {
            min = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void showShortestPath(int distances[], int numberVertices, int origin) {
    printf("Shortest path from vertex %d:\n", origin);
    for (int i = 0; i < numberVertices; i++) {
        printf("Vertex %d -> Vertex %d | Distance: %d\n", origin, i, distances[i]);
    }
}

void dijkstra(Graph* graph, int origin) {
    int distances[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < graph->numberVertices; i++) {
        distances[i] = INFINITY;
        visited[i] = false;
    }

    distances[origin] = 0;

    for (int count = 0; count < graph->numberVertices - 1; count++) {
        int u = findMinVertex(distances, visited, graph->numberVertices);
        visited[u] = true;

        for (int v = 0; v < graph->numberVertices; v++) {
            if (!visited[v] && graph->adjacentList[u][v] != INFINITY &&
                distances[u] + graph->adjacentList[u][v] < distances[v]) {
                distances[v] = distances[u] + graph->adjacentList[u][v];
            }
        }
    }

    showShortestPath(distances, graph->numberVertices, origin);
}
```

O algoritmo de Dijkstra é usado para encontrar o caminho mais curto de um vértice de origem para todos 
os outros vértices em um grafo ponderado (com pesos nas arestas). 

1. **Inicialização**:
   - O grafo é representado como uma estrutura de adjacência, onde `graph->adjacentList[i][j]` armazena o peso da aresta entre os vértices `i` e `j`.
   - A função `initializeGraph` inicializa o grafo, atribuindo pesos padrão de infinito (`INFINITY`) para todas as arestas. <br>
     O peso de uma aresta de um vértice para ele mesmo é zero.

2. **Adição de arestas**:
   - A função `addEdge` permite adicionar arestas ao grafo, especificando a origem, destino e peso da aresta.

3. **Encontrar o vértice com a menor distância**:
   - A função `findMinVertex` é usada para encontrar o vértice não visitado com a menor distância atual. <br>
     Ele percorre todas as distâncias dos vértices não visitados e retorna o índice do vértice com a menor distância.

4. **Exibição do caminho mais curto**:
   - A função `showShortestPath` exibe os caminhos mais curtos encontrados a partir do vértice de origem.

5. **Algoritmo de Dijkstra**:
   - A função `dijkstra` implementa o algoritmo de Dijkstra para encontrar os caminhos mais curtos.
   - Inicializa um array `distances` para armazenar as distâncias mais curtas dos vértices até a origem, e um array `visited` para acompanhar quais vértices foram visitados.
   - Define a distância da origem para si mesma como 0.
   - Para cada vértice não visitado, encontra o vértice não visitado mais próximo (menor distância) e o marca como visitado.
   - Atualiza as distâncias dos vértices adjacentes ao vértice selecionado se uma distância menor for encontrada.
   - O processo continua até que todos os vértices tenham sido visitados ou até que todas as distâncias tenham sido atualizadas.
   - Finalmente, exibe os caminhos mais curtos encontrados.

Este algoritmo garante encontrar o caminho mais curto entre o vértice de origem e todos os outros vértices em um grafo ponderado, 
desde que os pesos das arestas não sejam negativos.
