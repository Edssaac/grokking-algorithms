A busca binária é um algoritmo eficiente para encontrar um determinado elemento em uma lista ordenada.

```c
int binary_search(int list[], int item) {
    int low = 0; // Índice inicial da lista
    int high = sizeof(&list) - 1; // Índice final da lista
    int mid, guess; // Índice do elemento médio e o valor na posição média
    
    // Enquanto ainda houver elementos para procurar na lista
    while (low <= high) {
        mid = (low + high) / 2; // Calcula o índice do elemento médio
        guess = list[mid]; // Obtém o valor na posição média
        
        // Se o valor na posição média for igual ao item procurado
        if (guess == item) {
            return mid; // Retorna o índice do item encontrado
        }
       
        // Se o valor na posição média for maior que o item procurado
        if (guess > item) {
            high = mid - 1; // Reduz a busca à metade superior da lista
        } else { // Caso contrário
            low = mid + 1; // Reduz a busca à metade inferior da lista
        }
    }
    
    return -1; // Retorna -1 se o item não for encontrado na lista
}
```

Este algoritmo começa definindo um intervalo de busca na lista. Em seguida, calcula o índice do elemento médio desse intervalo e 
verifica se o elemento médio é o item que estamos procurando. Se for, retorna o índice desse item. Caso contrário, o algoritmo 
divide o intervalo de busca pela metade e continua procurando na metade apropriada da lista até encontrar o item ou até que o 
intervalo de busca se torne vazio, indicando que o item não está na lista.
