#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino) {
    if(n>0) {
        hanoi(n-1, origem, destino, auxiliar);
        printf("mova disco %d de %c para %c. \n", n, origem, destino);
        hanoi(n-1, auxiliar, origem, destino);
    }
}


int main(int argc, char const *argv[])
{
    hanoi(3, 'A', 'B', 'C');
}
