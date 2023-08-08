#include <stdio.h>
#include <stdlib.h>

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

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("BFS from vertex 0:\n");

    BFS(graph, 0);

    return 0;
}
