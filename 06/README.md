```c
struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numberVertices;
    struct Node** adjacentList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int numberVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numberVertices = numberVertices;
    graph->adjacentList = (struct Node*)malloc(numberVertices * sizeof(struct Node));

    for (int i = 0; i < numberVertices; i++) {
        graph->adjacentList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacentList[src];
    graph->adjacentList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacentList[dest];
    graph->adjacentList[dest] = newNode;
}

void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numberVertices * sizeof(int));
    int i;

    for (i = 0; i < graph->numberVertices; i++) {
        visited[i] = 0;
    }

    struct Node* queue = createNode(startVertex);
    visited[startVertex] = 1;

    while (queue != NULL) {
        int currentVertex = queue->data;

        printf("Visiting vertex %d\n", currentVertex);

        struct Node* temp = graph->adjacentList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;

            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue->next = createNode(adjVertex);
                queue = queue->next;
            }

            temp = temp->next;
        }

        struct Node* oldNode = queue;
        queue = queue->next;

        free(oldNode);
    }

    free(visited);
}
```

O algoritmo de busca em largura (BFS - Breadth-First Search) é usado para percorrer ou pesquisar em uma estrutura de dados do tipo grafo ou árvore. 
Ele começa pelo nó inicial e explora todos os seus vizinhos antes de seguir para os vizinhos dos vizinhos.

1. **Estruturas de Dados**:
   - `Node`: Representa um nó da lista encadeada. Cada nó tem um valor (`data`) e um ponteiro para o próximo nó na lista.
   - `Graph`: Representa o grafo. Contém o número de vértices e uma lista de adjacência.
   
2. **Funções Auxiliares**:
   - `createNode(int data)`: Cria um novo nó com o valor especificado.
   - `createGraph(int numberVertices)`: Cria um novo grafo com o número especificado de vértices. Inicializa a lista de adjacência como NULL para cada vértice.
   - `addEdge(struct Graph* graph, int src, int dest)`: Adiciona uma aresta entre os vértices `src` e `dest`, criando novos nós na lista de adjacência de cada um.
   
3. **Algoritmo BFS**:
   - `BFS(struct Graph* graph, int startVertex)`: Realiza a busca em largura a partir do vértice inicial `startVertex`.
     - Cria um array `visited` para acompanhar os vértices visitados e uma fila para armazenar os vértices a serem visitados.
     - Inicializa a fila com o vértice inicial e marca-o como visitado.
     - Enquanto a fila não estiver vazia, retira um vértice da fila, imprime sua visita e adiciona todos os seus vizinhos não visitados à fila.
     - O loop continua até que todos os vértices alcançáveis tenham sido visitados.
     - O código faz uso de uma fila simplificada implementada usando uma lista encadeada. Ele adiciona novos elementos no final da lista e remove do início.
     - É importante liberar a memória alocada para a fila e o array de visitados no final da função.
   
Esse algoritmo garante que todos os vértices conectados ao vértice inicial serão visitados antes de passar para os vértices mais distantes.
