## 👥 Módulo: Filas Dinâmicas (Queue)

### O que é uma Fila?

Se a Pilha opera sob a lei do "último a entrar é o primeiro a sair" (LIFO), a **Fila** adota a regra perfeitamente inversa. Trata-se de uma estrutura de dados linear e dinâmica governada pelo princípio **FIFO** (*First In, First Out* — O primeiro a entrar é, obrigatoriamente, o primeiro a sair).

É a reprodução exata de uma fila humana num banco ou supermercado:

* Quem chega para entrar na fila, posiciona-se obrigatoriamente no **Fim** (Tail/Rear).
* Quem conclui o seu objetivo e é atendido, sai obrigatoriamente pelo **Início** (Head/Front).
* Furar a fila ou remover alguém do meio viola a especificação da estrutura.

### Para que serve e Aplicações Reais

As filas são a engrenagem padrão da computação sempre que o sistema necessita gerir recursos escassos de forma **justa e sequencial**, garantindo que a ordem de solicitação seja respeitada. Na engenharia de sistemas, elas controlam:

1. **Sistemas de Mensageria e Streaming:** Buffers de vídeo (como no YouTube ou Netflix) utilizam filas de pacotes de dados. Os primeiros blocos descarregados da rede são os primeiros a ser renderizados na tela.
2. **Impressão em Rede:** Quando várias máquinas mandam documentos para a mesma impressora, o servidor organiza as requisições numa fila. Quem mandou o documento primeiro, imprime primeiro.
3. **Escalonamento de Processos (Round-Robin):** Sistemas operacionais gerem tarefas de mesma prioridade distribuindo tempos de CPU sequencialmente através de uma fila de execução.
4. **Algoritmos de Varredura em Redes:** Roteadores usam filas de pacotes na memória para gerir o tráfego que excede a largura de banda da interface.

### As Duas Operações Sagradas

Uma Fila pura possui duas funções exclusivas de mutação:

* **`enqueue` (Enfileirar):** Insere um novo nó no **Fim** da fila.
* **`dequeue` (Desenfileirar):** Remove o elemento que está no **Início** da fila e o devolve.

---

### 🖨️ Exercício 9: O Simulador de Spool de Impressão Industrial

**O Problema:**
Instalações fabris usam servidores centrais para gerir ordens de impressão de etiquetas e esquemas técnicos. Como as requisições chegam em massa de vários setores, o servidor armazena as tarefas numa **Fila Dinâmica** na *Heap*.

Você deve construir um sistema modular que gerencie este fluxo de trabalho. Cada nó da fila representará um documento e conterá o identificador numérico da ordem (`id_documento`) e o nome do arquivo.

**O Desafio Arquitetural (A Fila Dinâmica de Duas Extremidades):**
Para que a inserção (`enqueue`) e a remoção (`dequeue`) rodem com performance de tempo constante ($O(1)$), você não deve caminhar a lista inteira a cada inserção. Para evitar isso, a sua `main` gerenciará a fila através de uma estrutura controladora que rastreia as duas pontas simultaneamente.

Você deve implementar obrigatoriamente as seguintes structs:

```c
typedef struct Node {
    int id_documento;
    char nome_arquivo[50];
    struct Node *proximo;
} Node;

typedef struct {
    Node *inicio; // De onde saem os elementos (Head)
    Node *fim;    // Por onde entram os elementos (Tail)
} FilaImpressao;

```

Na `main`, instancie a fila (`FilaImpressao fila;`) e inicialize os ponteiros internamente como `NULL`. Implemente estritamente as seguintes funções modulares:

1. `void enqueue(FilaImpressao *f, int id, const char *nome)`
* Aloca dinamicamente um novo `Node` na Heap e copia os dados (use `snprintf` ou `strcpy` de forma segura para a string).
* **A Lógica dos Ponteiros:** Se a fila estiver vazia, o novo nó passa a ser o `inicio` e o `fim`. Se já contiver elementos, o nó atual do `fim` deve apontar o seu `proximo` para o novo nó, e a Fila atualiza o seu ponteiro de controle `fim` para o recém-chegado.


2. `void dequeue(FilaImpressao *f)`
* Se a fila não estiver vazia, resgata os dados do nó que está no `inicio`, atualiza o ponteiro de `inicio` para o `proximo` e libera a memória (`free`) do nó antigo.
* **Caso de Borda Crítico:** Se após a remoção a fila ficar completamente vazia, o ponteiro de controle `fim` também precisa ser explicitamente resetado para `NULL`. Caso contrário, ele se tornará um *Dangling Pointer* (ponteiro fantasma).
* Exiba na tela: `"Imprimindo: [ID %d] - Arquivo: %s\n"`. Se a fila estiver vazia, avise: `"Fila de impressão vazia.\n"`.


3. `void limparFila(FilaImpressao *f)`
* Percorre e desaloca todos os nós pendentes caso o usuário feche o programa antes do esvaziamento total da fila.



**Fluxo de Controle do Menu (`main`):**

* `1 [Nome do Arquivo]`: Enfileira um novo arquivo. O ID do documento deve ser gerado automaticamente e de forma sequencial pelo sistema (`101`, `102`, etc.) para manter a abstração limpa.
* `2`: Dispara o `dequeue` (processa/imprime a próxima tarefa da vez).
* `0`: Dispara `limparFila` e encerra de forma segura.

---

### ⚠️ Regras e Restrições de Engenharia (O Rigor Profissional)

1. **Higiene dos Ponteiros na Remoção:** Monitorar o esvaziamento completo na função `dequeue` é vital. Se `f->inicio` virar `NULL` mas `f->fim` continuar apontando para o bloco que acabou de sofrer `free`, a próxima inserção causará corrupção de memória.
2. **Programação Defensiva Oblíqua:** Como consolidado, valide o retorno do `malloc` para o novo nó dentro de `enqueue`.
3. **Limpeza Absoluta da Memória:** Nenhuma variável de controle pode ficar com lixo de memória ao inicializar, e nenhum byte pode ser deixado na Heap ao encerrar o software.