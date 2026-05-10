# Aula 01 — [Título do Conteúdo]

**Data:** DD/02/2026  
**Disciplina:** Estrutura de Dados  
**Professor:** Felipe CordeirO

---

## 📌 Conceitos da Aula

> Escreva aqui um resumo do que foi apresentado. O que é? Pra que serve? Onde é usado?

### Problemas e Instancias

> Problema != instancia  
Problema: somar dois numeros  
Instancia: 2 + 2  

> O problema e uma questao generica enquano a instancia e um caso especifico deste problema.

> Saber quantos pessoas estavam presentes em um comício  
O espaço tinha aproximadamente 100 pessoas sentadas e naquele momento estava razoavelmente cheia.  
* Qual o problema? Contagem dos elementos de um conjunto.
* Qual a instância? Pessoas numa sala de aula, comício, estádio, posto de
saúde, etc.  

Soluções:
#### S1: Contagem 1 por 1 com cuidado de não repetir.
Vantagem: Solução perfeita para um comício com poucas pessoasNão
exige saber nada sobre a quantidade do espaçoOperação de contagem.
Desvantagem: Quanto maior for o número de pessoas maior tempo para
contagemMaior possibilidade de erros de contagemPodem chegar novas pessoas.

#### S2: Contagem das cadeiras vazias e em seguida uma subtração com
relação ao número total de cadeiras.
Vantagem: Simples e funciona bem. Operação de contagem.
Desvantagem: Necessário saber o total de cadeira. Melhor quando houver
menos ausentes e pior quando houver menos presentes. Não funciona em
local público sem cadeiras.

#### S3: Estimativa baseada na metragem total da praça, multiplicada pelo
número estimado de pessoas por metro quadrado
Vantagem: Solução elegante e utilizada pela policia.
Desvantagem: Saber de antemão a metragem da praça e estimar a taxa de
pessoas por metro quadradoTambém é melhor se a população estiver
uniformemente distribuída.

#### S4: Organização por filas e contagem.
Vantagem: Método eficaz utilizado no exército, onde dada n filas com m
pessoas, ao multiplicar as filas, tem-se o total.
Desvantagem: Filas precisam estar organizadas e no cenários as cadeiras
estavam dispersas.

#### S5: Organização por filas e contagem por um líder da fila.
Vantagem: Versão em paralelo da primeira solução. Distribuindo-se a tarefa,
cada primeiro de fila tem entre 10 e 15 pessoas para contar em sua fila. Se a
soma foi correta o número obtido ao final do processo é exato.
Desvantagem: Leva-se um tempo para juntar todas as respostas, mas ainda
assim é uma boa solução.

#### S7: Todos os estudantes se levantam e se atribuem o número 1Em

seguida os alunos se organizam em pares. Em cada par, primeiro é
somado o número de cada um dos dois, um deles guarda este número e
permanece de pé, o outro deve se sentar. Os que ficaram em pé repetem
este processo até que só exista um único aluno em pé. Ele tem o número
exato de estudantes na sala.

### Torre de Hanoi
Checar codigo da aula.

### Recursão
A resolução recursiva de um problema geralmente é:

* se a instância é "pequena": resolva diretamente
* senão: reduza a uma instância menor do mesmo problema, aplique o método a instância menor e volte à isntância original

---

## 🧠 Pontos Importantes

- Ponto chave 1
- Ponto chave 2
- Dúvida pra resolver depois

---

## 💻 Exercícios

### Exercício 1 — [Título]

**Enunciado:**  
Descreva o que o exercício pede.

**Arquivo:** `aula-XX-exercicio-01.c`

**Lógica aplicada:**  
Antes de codificar, explique com palavras como você resolveu.

**Output esperado:**
```
exemplo de saída
```

**Status:** ✅ Funcionando / ⚠️ Com warnings / ❌ Pendente

---

### Exercício 2 — [Título]

**Enunciado:**  
Descreva o que o exercício pede.

**Arquivo:** `aula-XX-exercicio-02.c`

**Lógica aplicada:**  
Antes de codificar, explique com palavras como você resolveu.

**Output esperado:**
```
exemplo de saída
```

**Status:** ✅ Funcionando / ⚠️ Com warnings / ❌ Pendente

---

## 🔗 Referências

- [Link da documentação ou material usado]
- [Slide do professor]