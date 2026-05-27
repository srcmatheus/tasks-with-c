### 💾 Exercício 5: O Gerenciador de Buffer Dinâmico de Telemetria

**O Problema:**
Imagine um sistema de captação de dados de sensores industriais. O operador de controle digita as leituras de temperatura da máquina (números reais), mas não sabe antecipadamente quantas leituras fará no dia.

Sua tarefa é criar um programa modularizado que comece alocando um **array dinâmico pequeno** na Heap. À medida que o utilizador vai introduzindo os dados, se o array ficar completamente cheio, o seu programa deve **dobrar de tamanho automaticamente** em tempo de execução para comportar os novos dados, sem perder as leituras anteriores.

O programa deve parar de ler dados estritamente quando o utilizador introduzir o valor de escape `-999.0`. Ao encerrar, o sistema deve exibir um relatório estatístico e fazer a limpeza absoluta da memória.

**O Desafio Arquitetural (A Modularização Obrigatoria):**
Você deve estruturar o seu programa utilizando funções externas à `main`. Toda a gestão de capacidade deve ser feita passando o ponteiro do array por referência.

1. **A Estrutura de Inicialização:**
O seu array dinâmico deve começar na `main` com uma capacidade inicial de **apenas 2 elementos** do tipo `double`, alocados via `malloc` ou `calloc`.
2. `void adicionarLeitura(double array, int *tamanhoAtual, int *capacidadeMaxima, double novoDado)`
* Esta função recebe o endereço do ponteiro do array dinâmico (um **ponteiro para ponteiro**, `double `), pois se o array precisar mudar de lugar na RAM durante o redimensionamento, a alteração deve refletir na `main`.
* Recebe também os ponteiros para as variáveis de controle de fluxo: a quantidade de elementos inseridos (`tamanhoAtual`) e o limite atual alocado (`capacidadeMaxima`).
* **A Lógica de Otimização:** Se o `tamanhoAtual` atingir a `capacidadeMaxima`, a função deve disparar o `realloc`, **dobrando** a capacidade atual (`capacidadeMaxima *= 2`).
* *Nota de Engenharia:* Se o `realloc` falhar por falta de memória física no sistema operacional, o programa deve emitir um erro crítico e encerrar de forma segura, sem corromper o ponteiro original.


3. `void exibirRelatorioEstatistico(const double *array, int tamanhoAtual)`
* Esta função deve receber o array dinâmico em modo estritamente de leitura (`const`) e exibir:
1. A média aritmética de todas as temperaturas válidas digitadas.
2. A quantidade final de elementos inseridos vs. a capacidade máxima que o array terminou na Heap (ex: "Armazenados 5 elementos em um espaço alocado para 8").





---

### ⚠️ Regras e Restrições de Engenharia (O Rigor Máximo)

1. **Garantia contra Vazamento de Memória (Memory Leak):** Cada byte alocado na Heap via `malloc`/`realloc` deve ser explicitamente liberado usando a função `free()` antes do término do programa.
2. **Validação de Retorno da Alocação:** Nunca assuma que o sistema operacional tem memória disponível. O retorno de `malloc` e `realloc` **deve** ser checado contra `NULL`.
3. **Tratamento do Buffer de Entrada:** Mantenha as boas práticas desenvolvidas nos degraus anteriores. Entradas de caracteres inválidos não podem travar o seu programa.
4. **Uso Correto do Ponteiro Duplo (``):** Compreenda a diferença de quando usar `*array` para acessar a posição e quando usar `array` diretamente dentro da função de adição.