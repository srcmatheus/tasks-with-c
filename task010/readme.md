## 🔍 Busca Linear

A Busca Linear é o método mais direto para encontrar um elemento dentro de uma coleção de dados. Ela não exige nenhuma pré-condição da estrutura: o vetor pode estar completamente caótico e desordenado.

A mecânica é elementar: o algoritmo se posiciona no índice `0` do array e pergunta: *"É este o elemento que procuro?"*. Se não for, ele avança para o índice `1`, depois para o `2`, sucessivamente, inspecionando uma casa de cada vez até encontrar o alvo ou atingir o fim do vetor.

### Aplicações Reais

Embora seja ineficiente para grandes volumes de dados, a Busca Linear é amplamente utilizada em:

1. **Coleções Pequenas ou Desordenadas:** Quando o custo de ordenar o vetor é maior do que o custo de fazer uma varredura direta (ex: procurar um item em uma lista de compras de 10 elementos).
2. **Bases de Dados Não Indexadas:** Tabelas de bancos de dados recém-criadas ou logs brutos de texto onde os dados são gravados por ordem de chegada (Timestamp).
3. **Hardware Extremamente Limitado:** Em sistemas embarcados microcontrolados muito simples, onde o espaço de memória para carregar algoritmos complexos é escasso.

### A Análise de Complexidade ($O$)

* **Melhor Caso - $O(1)$:** O elemento procurado está na primeiríssima posição do vetor (índice 0). A CPU faz apenas uma comparação e encerra.
* **Pior Caso - $O(N)$:** O elemento está na última posição ou simplesmente **não existe** no vetor. O processador é obrigado a fazer $N$ comparações (onde $N$ é o tamanho do array). Se o vetor tiver 10 milhões de itens, serão 10 milhões de voltas no laço.

---

### 📦 Exercício 10: O Rastreador de Fraudes de Cartão de Crédito

**O Cenário de Negócio:**
Sistemas de segurança bancária monitoram transações em tempo real. Quando um cartão é clonado, os criminosos costumam fazer compras de valores idênticos em curtos intervalos de tempo para testar o limite do cartão. O seu papel é construir um módulo de auditoria que varra o histórico recente de transações de um cliente para identificar se um determinado valor suspeito foi repetido e em quais posições do registro ele ocorreu.

**O Problema:**
Escreva um programa modularizado em C que receba um vetor de inteiros representando os valores das transações financeiras de um cliente. O programa deve ler um "Valor Alvo Suspeito" e realizar uma **Busca Linear** para encontrar **todas** as ocorrências desse valor.

**O Desafio Arquitetural (A Restrição de Saída Dinâmica):**
Como o valor suspeito pode aparecer várias vezes, uma função de busca tradicional que retorna apenas o primeiro índice encontrado não resolve o problema do banco.

Você deve criar uma função de busca que identifique todas as posições e armazene esses índices encontrados em um **segundo vetor (vetor de resultados)**.

A sua `main` terá duas constantes rígidas:

```c
#define TAM_HISTORICO 10
#define TAM_RESULTADO 10

```

Você deve implementar, obrigatoriamente, a seguinte função modular:

```c
int buscaLinearMultipla(const int *historico, int tamanho, int alvo, int *indicesEncontrados);

```

* **`historico`**: O vetor contendo os valores das transações (estritamente para leitura: `const`).
* **`tamanho`**: O número de elementos no histórico (`TAM_HISTORICO`).
* **`alvo`**: O valor suspeito que estamos caçando.
* **`indicesEncontrados`**: Um vetor auxiliar que sua função preencherá com os índices do vetor original onde o alvo foi avistado.
* **Retorno (`int`)**: A função deve retornar a **quantidade total de vezes** que o elemento foi encontrado (o tamanho útil do vetor de resultados). Se não encontrar nenhuma, retorna `0`.

**Fluxo de Execução da `main`:**

1. Inicialize um vetor estático de transações com 10 valores inteiros quaisquer (ex: `{150, 40, 200, 40, 90, 40, 300, 120, 40, 50}`).
2. Solicite ao operador o valor suspeito a ser rastreado. Trate o buffer contra caracteres inválidos.
3. Dispare a função `buscaLinearMultipla`.
4. Se o retorno for maior que zero, use um laço na `main` para imprimir o vetor `indicesEncontrados` até o limite retornado pela função (ex: *"Valor suspeito encontrado nos índices: 1, 3, 5, 8"*). Se for zero, avise que a transação é segura.