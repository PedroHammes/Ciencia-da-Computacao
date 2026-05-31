// 5. Algoritmos de Busca
// Exercício: Escreva uma função de busca sequencial que percorra um vetor estático de inteiros e retorne 1 se encontrar o valor alvo, ou 0 caso não encontre. 
// Explique como o algoritmo garante que todo o vetor seja verificado.
// C - Guia do Programador (Aitkens e Jones): Dia 8 (Matrizes/Vetores).

// BIBLIOTECAS
#include <stdio.h>

// CONSTANTES
#define MAX 12

// VARIÁVEIS
int target, matriz[MAX] = {0, 1, 4, 2, 10, 3, 9, 5, 6, 11, 21, 19};
int search(int n, int array[], int size);

int main ()
{
    printf("Informe o valor a ser buscado: \n");
    scanf("%d", &target);

    printf("%d \n", search(target, matriz, MAX));

    return 0;
}

int search(int n, int array[], int size)
{
    for (int i=0; i < size; i++)
    {
        if (n == array[i]) { return 1; }
    }
    return 0;
}