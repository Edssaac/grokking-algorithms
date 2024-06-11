O algoritmo de ordenação por mistura (merge sort) segue o paradigma "dividir e conquistar".
Ele divide a matriz não ordenada em dois subarrays, ordena esses subarrays e, em seguida, mescla os subarrays ordenados para produzir 
a matriz final ordenada.

Vamos analisar o código:

```c
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
```

1. **merge(int arr[], int l, int m, int r)**:

   Esta função é responsável por mesclar dois subarrays ordenados em um único subarray ordenado. <br>
   Ela recebe como parâmetros o array original `arr`, os índices de início `l`, meio `m` e fim `r` dos subarrays.

   - Primeiro, ela calcula os tamanhos dos dois subarrays usando os índices fornecidos: `n1 = m - l + 1` e `n2 = r - m`.
   - Em seguida, ela cria dois subarrays temporários `L[]` e `R[]` para armazenar os elementos dos subarrays esquerdo e direito, respectivamente.
   - Os loops `for` são usados para copiar os elementos dos subarrays originais para os subarrays temporários.
   - Depois, ela mescla os dois subarrays temporários em ordem crescente, atualizando o array original `arr[]` conforme necessário.
   - Finalmente, quaisquer elementos restantes em `L[]` e `R[]` são copiados de volta para `arr[]`.

3. **mergeSort(int arr[], int l, int r)**: Esta é a função principal do merge sort.

   - Ela recebe como parâmetros o array original `arr[]` e os índices de início `l` e fim `r`.
   - Primeiro, verifica se o índice de início é menor que o índice de fim, o que garante que haja mais de um elemento para ordenar.
   - Em seguida, calcula o ponto médio `m` do array usando a fórmula `m = l + (r - l) / 2`.
   - A função é chamada recursivamente para os subarrays esquerdo (`l` até `m`) e direito (`m + 1` até `r`).
   - Por fim, os subarrays ordenados são mesclados usando a função `merge()`.

Este processo de dividir, ordenar e mesclar é repetido recursivamente até que todos os elementos estejam ordenados.

---

O algoritmo de ordenação por comparação (quick sort) também segue o paradigma "dividir e conquistar". 

```c
void quick_sort(int *array, int start, int end) {
	if (start < end) {
		int q = partition(array, start, end);

		quick_sort(array, start, q-1);
		quick_sort(array, q+1, end);
	}
}

int partition(int *array, int start, int end) {
	int pivot = array[end];
	int i = start - 1;
	int temp = 0;

	for (int j=start; j<end; j++) {
		if (array[j] <= pivot) {
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i+1];
	array[i+1] = array[end];
	array[end] = temp;

	return i+1;
}
```

Ele funciona da seguinte maneira:

1. **Escolha do pivô**: Um elemento do array é escolhido como pivô. Existem diferentes estratégias para a escolha do pivô, sendo a mais comum escolher o último elemento do array.

2. **Particionamento**: O array é rearranjado de forma que todos os elementos menores que o pivô fiquem antes dele e todos os elementos maiores que o pivô fiquem depois dele. No final desse processo, o pivô estará na sua posição final no array ordenado. Isso é feito pela função `partition()`.

3. **Recursão**: O algoritmo é aplicado recursivamente para as duas metades do array resultantes do passo anterior. Essa recursão é realizada pela função `quick_sort()`.

4. **Conquista**: O processo continua até que os subarrays tenham tamanho zero ou um, o que significa que o array está ordenado.

A função `partition()` é responsável pelo particionamento do array. Ela recebe como entrada o array, o índice inicial `start` e o índice final `end`. Dentro dessa função:

- O pivô é escolhido como o último elemento do array (`pivot = array[end]`).
- Um índice `i` é inicializado como `start - 1`.
- Um loop `for` itera sobre os elementos do array de `start` até `end - 1`.
  - Se o elemento atual for menor ou igual ao pivô, o índice `i` é incrementado, e os elementos nos índices `i` e `j` são trocados de lugar.
- No final do loop, o pivô é trocado com o elemento na posição `i + 1`, colocando-o na posição correta no array ordenado.
- O índice `i + 1` é retornado como o novo índice do pivô.

A função `quick_sort()` é a função principal que chama a função `partition()` e realiza a recursão. Ela recebe como entrada o array, o índice inicial `start` e o índice final `end`. Dentro dessa função:

- Se `start` for menor que `end`, ou seja, se ainda houver elementos no subarray a serem ordenados:
  - O pivô é obtido chamando a função `partition()`.
  - Em seguida, o `quick_sort()` é chamado recursivamente para as duas metades do array, uma que vai de `start` até `q-1` e outra que vai de `q+1` até `end`.

Essencialmente, o algoritmo de quick sort continua dividindo o array em partes menores, até que cada parte seja trivialmente ordenada 
(com zero ou um elemento), resultando em um array totalmente ordenado no final.
