#include <stdio.h>
#include <stdlib.h>

struct cel { 
    int matricula; /* Este campo armazena a matrícula do aluno */
    struct cel *next; /* Este ponteiro aponta para a próxima célula (próxima matricula) */
    struct cel *prev; /* Este ponteiro aponta para a célula anterior (matricula anterior) */
};

typedef struct cel Celula; /* Nome alternativo para struct cel */

/* ===================== MENU ===================== */
void ShowMenu() {
    printf("\n----------------------------------------\n");
    printf("MENU DE OPCOES\n");
    printf("1. Adicionar no inicio da lista\n");
    printf("2. Adicionar no final da lista\n");
    printf("3. Adicionar em um ponto especifico da lista\n");
    printf("4. Listar todos os elementos da lista\n");
    printf("5. Listar um elemento especifico da lista\n");
    printf("6. Excluir do inicio da lista\n");
    printf("7. Excluir do final da lista\n");
    printf("8. Excluir de um ponto especifico da lista\n");
    printf("9. Liberar os elementos e mostrar a lista vazia\n");
    printf("10. Terminar\n");
    printf("----------------------------------------\n");
    printf("Qual a sua opcao? ");
}

/* ===================== CRIAÇÃO ===================== */
Celula *createMatricula(int matricula) {
    Celula *newStudent = (Celula *)malloc(sizeof(Celula)); /* Reserva espaço de memória para uma célula */
    if (newStudent == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    newStudent->matricula = matricula; /* Coloca a matrícula na nova célula */
    newStudent->next = NULL; /* Inicializa o ponteiro para a próxima célula */
    newStudent->prev = NULL; /* Inicializa o ponteiro para a célula anterior */

    return newStudent;
}

/* ===================== AUXILIARES ===================== */
int listSize(Celula *start) {
    int count = 0;
    Celula *current = start;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int searchMatricula(Celula *start, int matricula) {
    Celula *current = start;

    while (current != NULL) {
        if (current->matricula == matricula) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

/* ===================== INSERÇÕES ===================== */
void addStart(Celula **start, Celula **end, int matricula) {
    Celula *newStudent = createMatricula(matricula);

    if (*start == NULL) {
        *start = newStudent;
        *end = newStudent;
    } else {
        newStudent->next = *start;
        (*start)->prev = newStudent;
        *start = newStudent;
    }

    printf("Matricula %d adicionada no inicio da lista.\n", matricula);
}

void addEnd(Celula **start, Celula **end, int matricula) {
    Celula *newStudent = createMatricula(matricula);

    if (*end == NULL) {
        *start = newStudent;
        *end = newStudent;
    } else {
        newStudent->prev = *end;
        (*end)->next = newStudent;
        *end = newStudent;
    }

    printf("Matricula %d adicionada no final da lista.\n", matricula);
}

void addAtPosition(Celula **start, Celula **end, int matricula, int position) {
    int size = listSize(*start);

    if (position < 1 || position > size + 1) {
        printf("Posicao invalida. A lista tem %d elemento(s).\n", size);
        return;
    }

    if (position == 1) {
        addStart(start, end, matricula);
        return;
    }

    if (position == size + 1) {
        addEnd(start, end, matricula);
        return;
    }

    Celula *newStudent = createMatricula(matricula);
    Celula *current = *start;
    int i = 1;

    while (i < position - 1) {
        current = current->next;
        i++;
    }

    newStudent->next = current->next;
    newStudent->prev = current;

    current->next->prev = newStudent;
    current->next = newStudent;

    printf("Matricula %d adicionada na posicao %d.\n", matricula, position);
}

/* ===================== LISTAGEM ===================== */
void listAll(Celula *start) {
    if (start == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Alunos presentes na lista:\n");
    Celula *current = start;
    int pos = 1;

    while (current != NULL) {
        printf("%d. Matricula: %d\n", pos, current->matricula);
        current = current->next;
        pos++;
    }
}

void listSpecific(Celula *start, int matricula) {
    Celula *current = start;
    int pos = 1;

    while (current != NULL) {
        if (current->matricula == matricula) {
            printf("Matricula encontrada na posicao %d.\n", pos);
            printf("Matricula: %d\n", current->matricula);
            return;
        }
        current = current->next;
        pos++;
    }

    printf("Matricula %d nao encontrada na lista.\n", matricula);
}

/* ===================== REMOÇÕES ===================== */
void removeStart(Celula **start, Celula **end) {
    if (*start == NULL) {
        printf("A lista esta vazia, nada para excluir.\n");
        return;
    }

    Celula *studentLeaving = *start;

    *start = (*start)->next;

    if (*start == NULL) {
        *end = NULL;
    } else {
        (*start)->prev = NULL;
    }

    printf("Matricula %d removida do inicio da lista.\n", studentLeaving->matricula);
    free(studentLeaving);
}

void removeEnd(Celula **start, Celula **end) {
    if (*end == NULL) {
        printf("A lista esta vazia, nada para excluir.\n");
        return;
    }

    Celula *studentLeaving = *end;

    *end = (*end)->prev;

    if (*end == NULL) {
        *start = NULL;
    } else {
        (*end)->next = NULL;
    }

    printf("Matricula %d removida do final da lista.\n", studentLeaving->matricula);
    free(studentLeaving);
}

void removeAtPosition(Celula **start, Celula **end, int position) {
    int size = listSize(*start);

    if (position < 1 || position > size) {
        printf("Posicao invalida. A lista tem %d elemento(s).\n", size);
        return;
    }

    if (position == 1) {
        removeStart(start, end);
        return;
    }

    if (position == size) {
        removeEnd(start, end);
        return;
    }

    Celula *current = *start;
    int i = 1;

    while (i < position) {
        current = current->next;
        i++;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    printf("Matricula %d removida da posicao %d.\n", current->matricula, position);
    free(current);
}

/* ===================== LIBERAR LISTA ===================== */
void freeList(Celula **start, Celula **end) {
    Celula *current = *start;
    Celula *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *start = NULL;
    *end = NULL;

    printf("Todos os elementos foram liberados. A lista esta vazia.\n");
}

/* ===================== MAIN ===================== */
int main() {
    Celula *start = NULL;
    Celula *end = NULL;
    int option = 0;

    while (option != 10) {
        ShowMenu();
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int matricula;
                printf("Informe a matricula do aluno que esta entrando no inicio: ");
                scanf("%d", &matricula);

                if (searchMatricula(start, matricula)) {
                    printf("Essa matricula ja esta na lista.\n");
                } else {
                    addStart(&start, &end, matricula);
                }
                break;
            }

            case 2: {
                int matricula;
                printf("Informe a matricula do aluno que esta entrando no final: ");
                scanf("%d", &matricula);

                if (searchMatricula(start, matricula)) {
                    printf("Essa matricula ja esta na lista.\n");
                } else {
                    addEnd(&start, &end, matricula);
                }
                break;
            }

            case 3: {
                int matricula, position;
                printf("Informe a matricula do aluno: ");
                scanf("%d", &matricula);

                if (searchMatricula(start, matricula)) {
                    printf("Essa matricula ja esta na lista.\n");
                } else {
                    printf("Informe a posição onde deseja inserir: ");
                    scanf("%d", &position);
                    addAtPosition(&start, &end, matricula, position);
                }
                break;
            }

            case 4:
                listAll(start);
                break;

            case 5: {
                int matricula;
                printf("Informe a matricula do aluno que deseja localizar: ");
                scanf("%d", &matricula);
                listSpecific(start, matricula);
                break;
            }

            case 6:
                removeStart(&start, &end);
                break;

            case 7:
                removeEnd(&start, &end);
                break;

            case 8: {
                int position;
                printf("Informe a posicao do aluno que deseja excluir: ");
                scanf("%d", &position);
                removeAtPosition(&start, &end, position);
                break;
            }

            case 9:
                freeList(&start, &end);
                break;

            case 10:
                freeList(&start, &end);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}