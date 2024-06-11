```c
#define K 3

typedef struct {
    double x;
    double y;
    char label;
} Point;

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

char predictClass(Point dataset[], Point query) {
    double distances[K];
    char labels[K];

    for (int i = 0; i < K; i++) {
        distances[i] = calculateDistance(dataset[i], query);
        labels[i] = dataset[i].label;
    }

    for (int i = K; i < sizeof(dataset) / sizeof(dataset[0]); i++) {
        double distance = calculateDistance(dataset[i], query);

        int maxIndex = 0;
        for (int j = 1; j < K; j++) {
            if (distances[j] > distances[maxIndex]) {
                maxIndex = j;
            }
        }

        if (distance < distances[maxIndex]) {
            distances[maxIndex] = distance;
            labels[maxIndex] = dataset[i].label;
        }
    }

    int countA = 0, countB = 0;
    for (int i = 0; i < K; i++) {
        if (labels[i] == 'A') {
            countA++;
        } else {
            countB++;
        }
    }

    return (countA > countB) ? 'A' : 'B';
}
```

Este código implementa o algoritmo de classificação k-nearest neighbors (k-NN). 

Vamos analisar o algoritmo:

1. **Definição de Constante K**:

   No início do código, é definida uma constante `K` com o valor 3. Isso determina quantos vizinhos mais próximos serão
   considerados para a classificação de um novo ponto.

3. **Definição da Estrutura Point**:

   É definida uma estrutura `Point` que representa um ponto no espaço, com coordenadas `x` e `y`, e um rótulo (`label`)
   que indica a classe do ponto (nesse caso, pode ser 'A' ou 'B').

5. **Função de Cálculo de Distância**:

   A função `calculateDistance` calcula a distância euclidiana entre dois pontos no espaço bidimensional usando o teorema de Pitágoras.

7. **Função de Predição de Classe (predictClass)**:

   Esta é a função principal que implementa o algoritmo k-NN para prever a classe de um novo ponto (`query`). <br>
   Aqui está o que ela faz:

   a. **Calcula Distâncias**:

   Para cada ponto no conjunto de dados (`dataset`), calcula a distância entre esse ponto e o ponto de consulta (`query`).
   Armazena as distâncias calculadas e os rótulos correspondentes em arrays separados.

   b. **Seleção dos Vizinhos Mais Próximos**:

   Depois de calcular as distâncias para todos os pontos no conjunto de dados, a função seleciona os K pontos mais próximos ao ponto de consulta.
   Inicialmente, ele armazena as distâncias e os rótulos dos primeiros K pontos. Em seguida, para os pontos restantes no conjunto de dados,
   compara suas distâncias com a maior distância atualmente armazenada entre os vizinhos mais próximos. Se a nova distância for menor, ela substitui
   a distância máxima e o rótulo correspondente na lista de vizinhos mais próximos.

   c. **Contagem dos Rótulos**:

   Depois de encontrar os K vizinhos mais próximos, a função conta quantos pontos pertencem a cada classe ('A' ou 'B') entre esses vizinhos.

   d. **Decisão de Classificação**:

   Com base na contagem de rótulos, a função decide qual classe atribuir ao ponto de consulta. Se houver mais pontos da classe 'A',
   ela retorna 'A', caso contrário, retorna 'B'.

Portanto, essa função usa a ideia de que pontos semelhantes tendem a estar na mesma classe e faz a classificação do novo ponto 
baseando-se nas classes dos seus K vizinhos mais próximos.
