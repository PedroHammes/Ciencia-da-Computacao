#include <stdio.h>
#include <stdlib.h>


struct cel { 
    int matricula; /* Este campo armazena a matrícula do aluno */
    struct cel *next; /* Este ponteiro aponta para a próxima célula (próxima matricula) */
    struct cel *prev; /* Este ponteiro aponta para a célula anterior (matricula anterior) */
};

typedef struct cel Celula; /* nome alternativo para struct cel */

void ShowMenu() {
    printf("Escolha uma opção: \n"
        "1. Adicionar no início da lista\n"
        "2. Adicionar no final da lista\n"
        "3. Adicionar em um ponto específico da lista\n"
        "4. Listar todos os elementos da lista\n"
        "5. Listar um elemento específico da lista\n"
        "6. Excluir do início da lista\n"
        "7. Excluir do final da lista\n"
        "8. Excluir de um ponto específico da lista\n"
        "9. Liberar os elementos e mostrar a lista vazia\n"
        "10. Terminar\n");
}

/* Função para criar uma nova célula com a matrícula fornecida */
Celula *createMatricula (int matricula) {
    Celula *newStudent = (Celula *)malloc(sizeof(Celula)); /* reserva espaço de memória para uma célula */
    newStudent->matricula = matricula; /* coloca a matrícula na nova célula */
    newStudent->next = NULL; /* inicializa o ponteiro para a próxima célula */
    newStudent->prev = NULL; /* inicializa o ponteiro para a célula anterior */
    return newStudent;
}

int main() {
    Celula *start = NULL;
    Celula *end = NULL;

    int option = 0;
    while (option != 10)
    {
        ShowMenu();
        scanf("%d", &option);
        switch (option)
        {
        case 1:{
            int matricula;
            printf("Informe a matrícula do aluno que está indo para o início da lista: ");
            scanf("%d", &matricula);
            Celula *newStudent = createMatricula(matricula);
            if (start == NULL) { /* se a lista estiver vazia */
                start = newStudent; /* o primeiro elemento da lista é a nova célula */
                end = newStudent; /* o último elemento da lista é a nova célula */
            }
            else { /* se a lista não estiver vazia */
                newStudent->next = start; /* o próximo elemento da nova célula é o primeiro elemento da lista */
                start->prev = newStudent; /* o elemento anterior ao primeiro elemento da lista é a nova célula */
                start = newStudent; /* o primeiro elemento da lista é a nova célula */
            }
            break;
        }
        case 2: {
            int matricula;
            printf("Informe a matrícula do aluno que está indo para o fim da lista: ");
            scanf("%d", &matricula);
            Celula *newStudent = createMatricula(matricula);
            if (end == NULL) {
                start = newStudent;
                end = newStudent;
            } else {
                newStudent->prev = end; /* O elemento anterior ao novo elemento é o ATUAL último elemento da lista */
                end->next = newStudent; /* O elemento seguinte ao ATUAL último elemento da lista é a nova célula */
                end = newStudent; /* Logo, o NOVO último elemento da lista é a nova célula */
            }
            break;
        }
        case 4:
            if (start == NULL)
            {
                printf("A lista está vazia, nada para exibir\n");
            }
            else
            {
                printf("Alunos presentes na lista:\n");
                Celula *current = start; /* ponteiro para percorrer a lista, começando em start*/
                while (current != NULL) /* enquanto o ponteiro atual não for nulo */
                {
                    printf("Matrícula: %d\n", current->matricula); /* exibe a matrícula do aluno atual*/
                    current = current->next; /* move o ponteiro para a próxima célula */
                }
            }
        case 10:
            /* code */
        default:
            break;
        }
    }
    

    return 0;
}