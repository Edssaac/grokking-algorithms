#include <stdio.h>
#include <math.h>

// Definindo a quantidade de vizinhos próximos (K)
#define K 3

// Estrutura para representar um ponto no espaço
typedef struct {
    double x;
    double y;
    char label;
} Point;

// Função para calcular a distância euclidiana entre dois pontos
double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Função para prever a classe de um ponto com base nos vizinhos mais próximos
char predictClass(Point dataset[], Point query) {
    double distances[K];
    char labels[K];

    // Calculando as distâncias e armazenando em 'distances'
    for (int i = 0; i < K; i++) {
        distances[i] = calculateDistance(dataset[i], query);
        labels[i] = dataset[i].label;
    }

    // Encontrando os K vizinhos mais próximos
    for (int i = K; i < sizeof(dataset) / sizeof(dataset[0]); i++) {
        double distance = calculateDistance(dataset[i], query);

        // Verificando se a distância é menor do que alguma das distâncias atuais
        int maxIndex = 0;
        for (int j = 1; j < K; j++) {
            if (distances[j] > distances[maxIndex]) {
                maxIndex = j;
            }
        }

        // Substituindo o vizinho mais distante pelo novo vizinho, se for o caso
        if (distance < distances[maxIndex]) {
            distances[maxIndex] = distance;
            labels[maxIndex] = dataset[i].label;
        }
    }

    // Contando as classes dos vizinhos mais próximos
    int countA = 0, countB = 0;
    for (int i = 0; i < K; i++) {
        if (labels[i] == 'A') {
            countA++;
        } else {
            countB++;
        }
    }

    // Retornando a classe com mais representantes entre os vizinhos
    return (countA > countB) ? 'A' : 'B';
}

int main() {
    // Dataset de exemplo
    Point dataset[] = {
        {1.0, 2.0, 'A'},
        {2.0, 3.0, 'A'},
        {3.0, 4.0, 'B'},
        {4.0, 5.0, 'B'}
    };

    // Ponto de consulta
    Point query = {2.5, 3.5, '?'};

    // Predizendo a classe do ponto de consulta
    char predictedClass = predictClass(dataset, query);

    printf("O ponto de consulta pertence a classe: %c\n", predictedClass);

    return 0;
}
