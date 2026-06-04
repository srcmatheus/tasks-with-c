### ⛓️ Exercício 6: O Gerenciador de Lista de Tarefas de CPU (Process Scheduler)

**O Problema:**
Sistemas operacionais gerenciam processos em execução utilizando estruturas dinâmicas. Você irá implementar de forma manual uma **Lista Encadeada Simples** que represente uma fila de tarefas a serem executadas pela CPU.

Cada nó da lista conterá o identificador único da tarefa (`id`), o tempo estimado de execução em ciclos (`ciclos`) e o ponteiro para o próximo nó da lista.

Sua tarefa é criar um programa modularizado que permita ao utilizador inserir dinamicamente processos na lista **de forma ordenada** (pelo número de ciclos, do menor para o maior) e, posteriormente, simular a execução consumindo a lista.

**O Desafio Arquitetural (A Estrutura):**
Você deve, obrigatoriamente, definir a estrutura do nó da seguinte forma:

```c
typedef struct No {
    int id;
    int ciclos;
    struct No *proximo;
} No;

```

A sua `main` deve inicializar o ponteiro da cabeça da lista como vazio (`No *cabeca = NULL;`). A manipulação da lista deve ocorrer estritamente através das seguintes funções:

1. `void inserirOrdenado(No cabeca, int id, int ciclos)`
* Esta função recebe o endereço do ponteiro da cabeça da lista (`No `).
* Ela deve alocar dinamicamente na *Heap* um novo `No`.
* **A Lógica Algorítmica:** O nó **não** deve ser inserido simplesmente no início ou no fim. Você deve percorrer a lista e inseri-lo na **posição correta** para que a lista permaneça sempre ordenada de forma crescente pelo campo `ciclos`.
* *Casos de borda obrigatórios a tratar:* A lista estar vazia; o novo nó ter menos ciclos que o primeiro elemento atual (inserção na cabeça); e o nó pertencer ao meio ou ao fim da lista.


2. `void executarProximaTarefa(No cabeca)`
* Esta função simula a CPU processando a tarefa com menor tempo (que, por estar ordenada, será sempre a primeira da lista, ou seja, a cabeça).
* Ela deve exibir na tela: `"Executando Tarefa ID X (%d ciclos)..."`.
* Em seguida, ela deve **remover esse nó da lista e liberar explicitamente a memória** (`free`) dele. O ponteiro `cabeca` na `main` deve ser atualizado para apontar para o sucessor do nó deletado. Se a lista estiver vazia, deve apenas avisar ao utilizador.


3. `void liberarLista(No cabeca)`
* Chamada obrigatoriamente antes do programa terminar para limpar a *Heap*. Deve percorrer toda a lista liberando nó por nó, até que `cabeca` volte a ser `NULL`.



**Fluxo de Execução:**

* O utilizador insere blocos de tarefas (`id` e `ciclos`) até digitar `id = 0`.
* A cada entrada válida, `inserirOrdenado` organiza o elemento em tempo real na memória.
* Quando o utilizador digitar `id = 0`, o programa para de receber dados e entra em um loop automático que chama `executarProximaTarefa` sucessivamente até que a lista fique completamente vazia.

---

### ⚠️ Regras e Restrições de Engenharia (O Rigor)

1. **Proibição Absoluta de Arrays Auxiliares:** Você não pode ler os dados em um vetor, ordená-lo (com *Bubble Sort*, etc.) e depois criar a lista. A ordenação deve acontecer **ponteiro por ponteiro**, diretamente na estrutura dos nós da *Heap* durante o ato de inserção.
2. **Proteção Antimemory Leak:** Monitore cirurgicamente a remoção de nós. Se você fizer `*cabeca = (*cabeca)->proximo` antes de guardar o endereço antigo ou dar o `free()`, você perderá o endereço do nó na *Heap*, gerando um vazamento de memória gravíssimo.
3. **Higiene na Validação de Alocação:** Como no Degrau 5, valide sempre se o retorno do `malloc` para o novo nó não é `NULL`.
4. **Robustez de Entrada:** Mantenha os seus laços de descarte de buffer (`getchar()`) ativos para entradas inválidas.