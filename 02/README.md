A ordenação por seleção é um algoritmo simples de ordenação que divide a lista em duas partes: uma parte ordenada e outra desordenada. 
O algoritmo encontra o menor elemento da parte desordenada e o coloca no final da parte ordenada, repetindo esse processo até que toda 
a lista esteja ordenada.

```c
void selectionSort(int arr[], int n) {
    int i, j, min_index, temp;

    // O loop externo percorre a lista da primeira posição até a penúltima posição
    for (i=0; i<n-1; i++) {
        // Assume que o elemento atual (na posição i) é o menor
        min_index = i;

        // O loop interno percorre os elementos restantes da lista
        for (j=i+1; j<n; j++) {
            // Se encontrarmos um elemento menor que o atualmente considerado como o menor...
            if (arr[j] < arr[min_index]) {
                // ...atualizamos o índice do menor elemento encontrado
                min_index = j;
            }
        }

        // Trocamos o elemento atual (na posição i) pelo menor elemento encontrado na parte desordenada
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
```

Basicamente, o algoritmo percorre a lista várias vezes. Em cada passagem, ele encontra o menor elemento na parte desordenada da lista 
e o move para a parte ordenada, até que toda a lista esteja ordenada.
