- `Struct`
    
    **Vetores (arrays)** armazenam uma coleção de elementos do mesmo tipo em posições consecutivas na memória.
    
    No entanto, no mundo real, os dados são mais complexos e nem sempre homogêneos. Imagine que você precisa agrupar informações que compõem uma entidade única — por exemplo, uma data que possui um `dia` (inteiro), um `mês` (inteiro) e um `ano` (inteiro).
    
    Pensando nisso, o `struct` foi desenvolvido.
    
- `Pointeiro`
    
    Objeto (ou variável) cujo valor armazenado é, na verdade, um **endereço de memória** apontando para outro valor.
    

Quando combinamos a `struct` com os `ponteiros`, criamos a base matemática das Estruturas de Dados dinâmicas: a **célula** (ou nó).

> Imagine essa célula como uma caixa dividida em duas partes 📦:
> 
> 1. A primeira parte guarda a informação real (um número, um nome, ou a nossa `struct Data`).
> 2. A segunda parte guarda um ponteiro.

Pensando na ideia de uma **Lista Encadeada** 🔗, **este ponteiro de dentro de uma célula deve apontar para a célula seguinte** para que várias células soltas na memória formem uma sequência contínua.

- `Célula`
    
    ```c
    typedef struct Celula {
        int valor;
        struct Celula *prox;
    } Celula;
    ```
    

Pensando nesse encadeamento, nós precisamos saber onde essa sequência termina. Para isso o ponteiro da **última** célula da lista deve armazenar o valor `null`  

- `Fila`
    
    Funciona sob a regra **FIFO** (*First-In-First-Out*), ou seja, o primeiro elemento a entrar é o primeiro a ser removido (exatamente como uma fila de banco).
    
- `Pilha`
    
    Funciona sob a regra **LIFO** (*Last-In-First-Out*), onde o último item colocado (no topo) é o primeiro a ser retirado (como um monte de pratos em uma prateleira).

