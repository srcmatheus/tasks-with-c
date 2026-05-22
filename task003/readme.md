### 🗺️ Exercício 3: O Sistema de Geometria de Grade (Grid Navigation)

**O Problema:**
Imagine o desenvolvimento do motor de física de um jogo em 2D ou o sistema de movimentação de um robô aspirador de pó. O robô se move em um plano cartesiano bidimensional ($X, Y$).

Você deve criar um programa modularizado que gerencie as coordenadas de um ponto no espaço através de comandos numéricos, utilizando **estritamente funções externas à `main**`.

O programa deve ler comandos do usuário em um laço:

* Se o usuário digitar `1` (Mover Norte): Incrementa $Y$ em 1.
* Se o usuário digitar `2` (Mover Sul): Decrementa $Y$ em 1.
* Se o usuário digitar `3` (Mover Leste): Incrementa $X$ em 1.
* Se o usuário digitar `4` (Mover Oeste): Decrementa $X$ em 1.
* Se o usuário digitar `0`: O programa encerra e exibe as coordenadas finais e a distância total percorrida.

**O Desafio Arquitetural (A Modularização):**
A função `main` **não** deve conter a lógica de movimentação, nem o cálculo da distância. Você deve obrigatoriamente implementar as seguintes funções:

1. `void processarMovimento(int comando, int *x, int *y)`
* Esta função recebe o comando digitado e os **endereços de memória** das coordenadas atuais do robô. Ela deve alterar diretamente os valores de $X$ e $Y$ na memória da `main` usando ponteiros.


2. `double calcularDistanciaOrigem(int x, int y)`
* Esta função recebe as coordenadas atuais **por valor** e calcula a distância em linha reta do ponto atual $(X, Y)$ até a origem $(0, 0)$.
* *Fórmula matemática:* $Distancia = \sqrt{X^2 + Y^2}$
* *Dica de biblioteca:* Pode usar a função `sqrt()` da biblioteca `<math.h>`. (Lembre-se de compilar incluindo a flag `-lm` se necessário, ex: `gcc programa.c -lm`).



**Exemplo de Execução:**

* O robô começa em $(0,0)$.
* Comandos digitados: `1` (Norte), `3` (Leste), `3` (Leste), `0` (Sair).
* Coordenada final: $(2, 1)$.
* Distância até a origem: $\sqrt{2^2 + 1^2} = \sqrt{5} \approx 2.24$.

---

### ⚠️ Regras e Restrições de Engenharia (O Rigor)

1. **Proibição de Variáveis Globais:** Está terminantemente proibido declarar variáveis fora das funções (no escopo global do arquivo). O estado do robô ($X, Y$) deve nascer dentro da `main` e ser manipulado estritamente via passagem de ponteiros.
2. **Manipulação Correta de Ponteiros:** Na função `processarMovimento`, certifique-se de usar o operador de derreferenciação (`*`) corretamente para alterar o valor apontado, e não o endereço do ponteiro.
3. **Tratamento de Erros e Casos de Borda:** Se o usuário digitar um comando inválido (como `5` ou uma letra), o sistema deve avisar "Comando Inválido", limpar o buffer e **não alterar** a posição do robô.
4. **Assinatura de Funções (Protótipos):** Declare os protótipos das funções no topo do arquivo (antes da `main`) e implemente-as abaixo da `main`. Isso garante a boa prática de organização de código em C.