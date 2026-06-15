## 📚 Módulo: Pilhas Dinâmicas (Stack)

### O que é uma Pilha?

Se as listas encadeadas que você estudou são a "matéria-prima", a Pilha é um produto de engenharia finalizado. Trata-se de uma estrutura de dados linear e dinâmica, mas com uma **regra restritiva de comportamento**.

Nas listas, você podia inserir ou remover nós de qualquer lugar (início, meio ou fim). Na Pilha, você perde essa liberdade em troca de previsibilidade e velocidade ($O(1)$). A regra de ouro aqui é o conceito **LIFO** (*Last In, First Out* — O último a entrar é, obrigatoriamente, o primeiro a sair).

Imagine uma pilha física de pratos na sua cozinha:

* O único prato com o qual você consegue interagir imediatamente é o que está no **Topo**.
* Se colocar um prato novo, ele vai para o Topo (**Push**).
* Se retirar um prato, você retira o do Topo (**Pop**).
* Se tentar puxar o prato da base ou do meio diretamente, a estrutura colapsa.

### Para que serve e Aplicações Reais

As pilhas são fundamentais quando o sistema precisa registrar ações e depois **reverter o caminho**, priorizando o evento mais recente. Na indústria de software, elas gerenciam:

1. **Mecanismo de Desfazer/Refazer (Undo/Redo):** O exercício anterior do editor de texto que você fez é, conceitualmente, uma pilha (ou duas pilhas trabalhando em conjunto).
2. **Histórico de Navegação:** Quando você clica no botão "Voltar" do navegador Web, o sistema faz um *Pop* na pilha de URLs para te devolver à última página visitada.
3. **Avaliação de Expressões e Compiladores:** Analisadores sintáticos usam pilhas para checar se a abertura e fechamento de parênteses, chaves e colchetes em códigos estão corretos.
4. **A Call Stack do Processador:** O próprio computador gerencia as chamadas de funções do seu programa empilhando contextos na memória *Stack*.

### As Duas Operações Sagradas

Uma pilha pura possui apenas duas funções de modificação de dados:

* **`push` (Empilhar):** Adiciona um elemento no topo.
* **`pop` (Desempilhar):** Remove o elemento do topo e o devolve para quem chamou.

---

### 🧱 Exercício 8: O Verificador de Sintaxe de Código (Syntax Checker)

**O Problema:**
Escreva um programa modularizado em C que simule a primeira etapa de um compilador: a validação de escopos. O programa deve ler uma cadeia de caracteres (uma fórmula ou linha de código) informada pelo usuário e determinar se os delimitadores de escopo estão balanceados de forma correta e na ordem matemática válida.

Os delimitadores válidos são os pares: `()`, `[]` e `{}`.

**Regras de Validação:**

* **Correto:** `{[()](%d)}` (Tudo o que abriu fechou na ordem certa).
* **Incorreto:** `{[}(]` (Fechou o colchete antes do parêntese terminar).
* **Incorreto:** `(()` (Sobrou um parêntese aberto).
* **Incorreto:** `)` (Tentou fechar algo que nunca foi aberto).

**O Desafio Arquitetural (A Pilha Dinâmica):**
Você deve processar o texto lido caractere por caractere. Toda vez que encontrar um símbolo de abertura (`(`, `[`, `{`), você deve dar um **`push`** desse caractere na Pilha. Toda vez que encontrar um símbolo de fechamento (`)`, `]`, `}`), você deve dar um **`pop`** na pilha e verificar se o caractere retirado casa com o par de fechamento.

Você deve implementar a estrutura usando nós alocados dinamicamente na *Heap*:

```c
typedef struct Node {
    char simbolo;
    struct Node *proximo;
} Node;

```

A sua `main` gerenciará o topo da pilha (`Node *topo = NULL;`). É obrigatório implementar as seguintes assinaturas:

1. `void push(Node topo, char c)`
* Aloca dinamicamente um novo nó e o posiciona no topo da pilha.


2. `char pop(Node topo)`
* Se a pilha não estiver vazia, remove o nó do topo, resgata o caractere salvo, dá `free` no nó e atualiza o topo. Devolve o caractere. Se estiver vazia, retorna um caractere neutro (como `\0`).


3. `void limparPilha(Node topo)`
* Garante a liberação de qualquer resíduo na Heap caso o processamento termine antes.



**Fluxo da `main`:**

* Solicite uma string ao usuário (pode usar o `scanf` tradicional ou ler uma linha usando `fgets`).
* Varra a string em um laço caractere por caractere.
* Ao fim do processamento, analise o estado da pilha: se ela terminou vazia e não houve erros no caminho, a sintaxe está correta. Caso contrário, acuse o erro.

---

### ⚠️ Regras e Restrições de Engenharia

1. **Abstração de String Limita:** Como o objetivo é treinar a lógica da estrutura de dados, o tamanho máximo do texto inserido pode ser limitado a um array estático na `main` de tamanho fixo (ex: `char entrada[100]`), mas a pilha **deve obrigatoriamente ser dinâmica**, alocada nó por nó via `malloc` na *Heap*.
2. **Casos de Borda do `pop`:** Trate o erro de *Stack Underflow* (quando o usuário digita apenas um parêntese de fechamento `)` com a pilha vazia). Seu programa não pode quebrar.
3. **Gerenciamento Estrito de Memória:** Certifique-se de dar `free` em cada nó removido no `pop`. Se restarem elementos abertos ao fim (ex: usuário digitou `(((`), a função `limparPilha` deve ser acionada antes de encerrar o programa para garantir 0 bytes de vazamento.