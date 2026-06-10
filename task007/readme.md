### 🗂️ Exercício 7: O Mecanismo de Histórico "Desfazer/Refazer" (Undo/Redo)

**O Contexto de Engenharia:**
Em editores de texto, softwares de modelagem 3D ou IDEs de desenvolvimento, o sistema mantém um registro sequencial das ações do utilizador. Para permitir que ele navegue livremente para trás (Desfazer/Undo) e para a frente (Refazer/Redo), a estrutura ideal é uma Lista Duplamente Encadeada, controlada por um ponteiro móvel que representa o estado atual na linha do tempo.

**O Problema:**
Você deve implementar manualmente uma Lista Duplamente Encadeada que armazene o histórico de estados de um documento. Cada estado será representado por um identificador numérico de alteração (`id_acao`).

Diferente dos exercícios anteriores, a sua `main` não terá apenas um ponteiro para a cabeça da lista. Você gerenciará a lista através de uma estrutura de controle centralizada e de um ponteiro cursor (o estado atual).

Sua `main` deve inicializar a seguinte estrutura de controle:

```c
typedef struct {
    NoDuplo *head;        // Aponta para a primeira ação do histórico
    NoDuplo *tail;        // Aponta para a última ação do histórico
    NoDuplo *atual;       // O cursor móvel (onde o usuário está na linha do tempo)
} Historico;

```

Você deve implementar, obrigatoriamente, as seguintes funções modulares:

1. `void registrarAcao(Historico *h, int id_acao)`
* Aloca dinamicamente um novo `NoDuplo` contendo o `id_acao`.
* **A Regra de Negócio Crítica (Ramificação do Tempo):** Se o cursor `h->atual` não estiver na ponta final da lista (`h->tail`) e o usuário registrar uma nova ação, **todos os nós que estavam à frente do cursor atual (o futuro que foi desfeito) devem ser imediatamente eliminados da Heap (`free`)**. A nova ação passa a ser o novo fim (`tail`) da lista.
* Se a lista estiver vazia, o novo nó torna-se a `head`, `tail` e `atual`.


2. `void desfazer(Historico *h)`
* Se for possível voltar no tempo, move o ponteiro `h->atual` para o nó `anterior`.
* Exibe na tela: `"Undo executado. Estado atual: ID %d\n"`. Se não houver ações para desfazer, avisa ao usuário.


3. `void refazer(Historico *h)`
* Se houver um "futuro" disponível (ou seja, se o usuário desfez algo e não inseriu nenhuma ação nova), move o ponteiro `h->atual` para o nó `proximo`.
* Exibe na tela: `"Redo executado. Estado atual: ID %d\n"`. Se não houver ações para refazer, avisa ao usuário.


4. `void limparHistorico(Historico *h)`
* Libera absolutamente todos os nós remanescentes na *Heap* antes do programa encerrar.



**Fluxo de Execução:**
O programa lerá comandos em um laço:

* `1 X`: Registra uma nova ação com o ID `X` (ex: `1 101`).
* `2`: Dispara o comando Desfazer (Undo).
* `3`: Dispara o comando Refazer (Redo).
* `0`: Encerra o programa (disparando a limpeza do histórico).

---

### ⚠️ Regras de Rigor Técnico

1. **Costura Perfeita de Ponteiros:** Certifique-se de tratar os ponteiros `proximo` e `anterior` em todas as inserções e remoções. Cuidado especial para não tentar acessar `ponteiro->anterior` se o ponteiro for `NULL`.
2. **Gestão de Memória na Ramificação:** Ao apagar o "futuro" na função `registrarAcao`, certifique-se de dar `free()` em todos os nós descartados para zerar qualquer chance de vazamento de memória.
3. **Proteções de Entrada:** Mantenha a blindagem de inputs contra caracteres e dados inválidos no laço de controle da `main`.