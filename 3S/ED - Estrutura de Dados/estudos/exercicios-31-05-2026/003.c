// 3. Revisão de Linguagem C
// Exercício: Escreva um laço while que imprima apenas os números pares de 2 a 10.
// Explique como a condição do laço e o incremento da variável garantem que o programa não entre em loop infinito.
// C - Guia do Programador (Aitkens e Jones): Dia 6 (Controle de Fluxo).

#include <stdio.h>

int main () 
{
    for (int control = 2; control < 11; control++)
    {
        if (control % 2 == 0) { printf("%d \n", control); }
    }    
}