// 4. Vetores, Structs e Ponteiros
// Exercício: Defina uma struct chamada Ponto contendo duas coordenadas inteiras (x e y).           [V]
// Declare um ponteiro para essa estrutura e aloque memória para ela usando malloc.                 [/]
// Explique por que usamos o operador de seta (->) em vez do ponto (.) para atribuir valores.       [ ]
// C - Guia do Programador (Aitkens e Jones): Dia 11 (Estruturas) e Dia 15 (Ponteiros Avançados).

#include <stdlib.h>
void *malloc(size_t size);

int main ()
{
    // Declaração da estrutura
    struct Ponto {
        int x;
        int y;
    } meuPonteiro = {1,5};

    
    // A declaração de um ponteiro segue a estrutura:
    //  nometipo nomeponteiro
    // No caso o nometipo é uma estrutura chamada Ponto, logo:
    struct Ponto *p_ponto;

    // E o ponteiro recebe o endereço de uma variável do tipo especificado, logo:
    // p_ponto = &meuPonteiro;

    // Mas o que queremos é alocar memória para a estrutura:
    // A função malloc aloca um bloco de memória do tamanho especificado e retorna um ponteiro para o início desse bloco.
    // O sizeof(struct Ponto) calcula o tamanho necessário para armazenar uma estrutura do tipo Ponto.  
    p_ponto =  malloc(sizeof(struct Ponto)); 
}