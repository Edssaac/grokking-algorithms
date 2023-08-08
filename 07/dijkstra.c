#include <stdio.h>
#include <stdbool.h>

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

int main() {
    Graph graph;
    int numberVertices, numerEdges;
    int origin, destiny, weight;

    printf("Enter the number of graph vertices: ");
    scanf("%d", &numberVertices);

    initializeGraph(&graph, numberVertices);

    printf("Enter the number of edges of the graph: ");
    scanf("%d", &numerEdges);

    for (int i = 0; i < numerEdges; i++) {
        printf("Enter the origin, destiny and weight of the edge %d: ", i + 1);
        scanf("%d %d %d", &origin, &destiny, &weight);
        addEdge(&graph, origin, destiny, weight);
    }

    printf("Enter the origin vertex: ");
    scanf("%d", &origin);

    dijkstra(&graph, origin);

    return 0;
}
