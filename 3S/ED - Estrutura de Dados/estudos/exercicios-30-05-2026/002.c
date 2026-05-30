// 2. Recursão
// Exercício: Escreva uma função recursiva somaAteN(int n) que retorne a soma de todos os números de 1 até $n$. Explique qual é a condição (caso base) que faz a recursão parar.
// C - Guia do Programador (Aitkens e Jones): Dia 5 (Funções e Recursividade).

#include <stdio.h>

int numero;
int somaAteN(int n);

int main()
{
    puts("Informe até que número deve ser contado: "); // puts é mais leve e recomendado quando não queremos exibir variáveis.
    scanf("%d", &numero);

    printf("A soma de 1 até %d é %d", numero, somaAteN(numero));

    return 0;
}

// ESPAÇO RESERVADO PARA FUNÇÕES.
int somaAteN (int n) 
{
    if (n == 1)
    {
        return n;
    }
    else 
    {
        return n + somaAteN(n-1);
    }
} 