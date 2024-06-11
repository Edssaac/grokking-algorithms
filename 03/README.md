Recursão é um conceito em programação onde uma função chama a si mesma para resolver um problema. 

Vamos analisar o código linha por linha:

```c
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return (n * factorial(n-1));
}
```

1. A função `factorial` recebe um argumento `n`, que é o número para o qual queremos calcular o fatorial.

2. A primeira coisa que a função faz é verificar se `n` é menor ou igual a 1. Se for, retorna imediatamente 1, pois o fatorial de 0 ou 1 é sempre 1.

3. Se `n` for maior que 1, então a função retorna o resultado de `n` multiplicado pelo fatorial de `n-1`.

Aqui está o ponto crucial da recursão: 

A função `factorial` chama a si mesma, passando `n-1` como argumento. Isso significa que ela vai calcular o 
fatorial de `n-1`, e isso por sua vez chama novamente a função com um valor menor até que eventualmente 
alcance o caso base (n <= 1), quando a recursão termina.

Por exemplo, se chamarmos `factorial(5)`, aconteceria o seguinte:

- `factorial(5)` retorna `5 * factorial(4)`
- `factorial(4)` retorna `4 * factorial(3)`
- `factorial(3)` retorna `3 * factorial(2)`
- `factorial(2)` retorna `2 * factorial(1)`
- `factorial(1)` retorna 1, pois atinge o caso base.

Então, substituindo de volta:

- `factorial(2)` retorna `2 * 1 = 2`
- `factorial(3)` retorna `3 * 2 = 6`
- `factorial(4)` retorna `4 * 6 = 24`
- `factorial(5)` retorna `5 * 24 = 120`

Esse processo é a essência da recursão: a função resolve um problema menor do que o original, chamando-se repetidamente até chegar a um ponto onde o problema é trivial de resolver.
