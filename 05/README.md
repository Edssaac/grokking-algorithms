```c
#define MAX_SIZE 10

typedef struct {
    char key[50];
    int value;
} Box;

typedef struct {
    Box* boxes[MAX_SIZE];
} HashTable;

HashTable* createHashTable() {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));

    for (int i = 0; i < MAX_SIZE; i++) {
        table->boxes[i] = NULL;
    }

    return table;
}

int calculateIndex(char* key) {
    int sum = 0;

    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    return sum % MAX_SIZE;
}

void insertOnHashTable(HashTable* table, char* key, int value) {
    int index = calculateIndex(key);
    Box* elemento = (Box*) malloc(sizeof(Box));

    strcpy(elemento->key, key);
    elemento->value = value;
    table->boxes[index] = elemento;
}

int searchOnHashTable(HashTable* table, char* key) {
    int index = calculateIndex(key);
    Box* elemento = table->boxes[index];

    if (elemento != NULL && strcmp(elemento->key, key) == 0) {
        return elemento->value;
    }

    return -1; // Not found
}

void removeFromHashTable(HashTable* table, char* key) {
    int index = calculateIndex(key);
    Box* elemento = table->boxes[index];

    if (elemento != NULL && strcmp(elemento->key, key) == 0) {
        free(elemento);
        table->boxes[index] = NULL;
    }
}

void freeHashTable(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table->boxes[i] != NULL) {
            free(table->boxes[i]);
        }
    }

    free(table);
}
```

Este código implementa uma tabela hash, que é uma estrutura de dados utilizada para armazenar pares chave-valor de forma eficiente.

1. **Estrutura de Dados**:
   - A estrutura `Box` representa cada elemento na tabela hash, contendo uma chave (`key`) e um valor (`value`).
   - A estrutura `HashTable` contém um array de ponteiros para `Box`, chamado `boxes`.

2. **Criação da Tabela Hash** (`createHashTable()`):
   - Essa função aloca memória para uma tabela hash e inicializa todos os ponteiros de `boxes` como `NULL`.

3. **Cálculo do Índice** (`calculateIndex()`):
   - Esta função calcula um índice para uma determinada chave. O cálculo do índice é feito somando os valores ASCII dos caracteres da chave e então tirando o módulo do resultado com o tamanho máximo da tabela (`MAX_SIZE`). Isso ajuda a distribuir os elementos de forma mais uniforme na tabela.

4. **Inserção de Elementos** (`insertOnHashTable()`):
   - Esta função insere um par chave-valor na tabela hash.
   - Calcula o índice usando `calculateIndex()`.
   - Aloca memória para um novo `Box`, preenche-o com a chave e o valor fornecidos e, em seguida, armazena-o na posição correspondente na tabela.

5. **Busca na Tabela Hash** (`searchOnHashTable()`):
   - Esta função busca um valor correspondente a uma chave na tabela hash.
   - Calcula o índice usando `calculateIndex()`.
   - Verifica se há um elemento na posição calculada e se a chave corresponde à chave procurada. Se encontrar, retorna o valor.

6. **Remoção de Elementos** (`removeFromHashTable()`):
   - Esta função remove um elemento da tabela hash.
   - Calcula o índice usando `calculateIndex()`.
   - Verifica se há um elemento na posição calculada e se a chave corresponde à chave procurada. Se encontrar, libera a memória ocupada pelo `Box`.

7. **Liberar Memória** (`freeHashTable()`):
   - Esta função libera toda a memória alocada para a tabela hash e seus elementos.

Essa implementação é bastante básica e não trata colisões, ou seja, situações em que duas chaves diferentes resultam no mesmo índice. 
Para lidar com colisões, geralmente são utilizadas técnicas como encadeamento separado ou resolução por sondagem.

Tabelas hash são estruturas de dados eficientes que usam funções de hash para armazenar e acessar informações. 
Elas oferecem acesso rápido aos dados, com inserção e busca em tempo constante, em média. 
Amplamente utilizadas na computação, exigem uma boa função de hash e tamanho adequado para otimizar o desempenho.
