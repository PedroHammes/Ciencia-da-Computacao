// 1. Problemas, Algoritmos e Programas
// Exercício: Escreva um programa em C que leia a base e a altura de um triângulo e calcule sua área. Explique como o seu código divide o problema nas três etapas fundamentais: entrada, processamento e saída.
// C - Guia do Programador (Aitkens e Jones): Dia 2 (Componentes de um programa) e Dia 4 (Expressões).

// EXPLICAÇÃO
// <stdio.h> biblioteca usada para lidar com Input e Output;
// Declaração de variáveis.
// Função principal.
//  Inputs
//  Cálculo da área do triângulo. A divisão por 2.0 em vez de 2 serve para garantir a casa decimal no resultado.
//  Return com %.1f garante a precisão de uma casa decimal no output.

#include <stdio.h>

int base, altura;
double area;


int main() {

    printf("Informe o valor da base do triângulo: ");
    scanf("%d", &base);
    
    printf("Informe o valor da altura do triângulo: ");
    scanf("%d", &altura);

    area = (base*altura)/2.0; // </2.0> garante a casa decimala na resolução.

    printf("Um triângulo com base(%d) e altura(%d) possui area: %.1f \n", base, altura, area);

    return 0;
}