### 📉 Exercício 2: O Rastreador de Subsequência Crescente Máxima

**O Problema:**
O utilizador irá introduzir uma sequência de números inteiros positivos, **um de cada vez**. O fluxo de dados será encerrado estritamente quando o utilizador digitar o número `0`.

Sua tarefa é monitorizar essa sequência em tempo real e, ao final (quando `0` for digitado), exibir:

1. O **comprimento** (quantidade de elementos) da **maior subsequência contínua que seja estritamente crescente**.
2. A **soma** dos elementos dessa maior subsequência específica.

**Exemplo de Execução:**

* **Entradas fornecidas pelo utilizador (uma por uma):** `3`, `5`, `8`, `2`, `1`, `4`, `7`, `9`, `12`, `3`, `0`
* **Análise das subsequências crescentes no fluxo:**
* `3, 5, 8` $\implies$ Comprimento: 3, Soma: 16
* `2` $\implies$ Comprimento: 1, Soma: 2
* `1, 4, 7, 9, 12` $\implies$ Comprimento: 5, Soma: 33  *(Esta é a maior!)*
* `3` $\implies$ Comprimento: 1, Soma: 3


* **Saída Esperada:**
`Maior subsequencia crescente: 5 elementos`
`Soma da maior subsequencia: 33`

*(Nota: Se houver empate no comprimento entre duas subsequências diferentes, o critério de desempate fica a seu critério arquitetural, mas documente sua escolha).*

---

### ⚠️ Regras e Restrições de Engenharia (O Rigor)

1. **Memória Estática Restrita ($O(1)$ em Espaço):** Está **proibido** o uso de qualquer tipo de vetor (`int dados[100]`) ou alocação dinâmica. Você não sabe se o utilizador vai digitar 10 ou 10.000 números antes do `0`. O seu algoritmo deve resolver o problema utilizando apenas um conjunto fixo e reduzido de variáveis escalares na *Stack*.
2. **Complexidade de Tempo Ótima ($O(N)$):** O fluxo deve ser processado em uma única passagem. Não é permitido pedir para o utilizador redigitar números ou criar loops aninhados redundantes que reanalisem dados passados.
3. **Imunidade a Entradas Inválidas:** O seu programa **não pode quebrar ou entrar em loop infinito** se o utilizador digitar uma letra ou um caractere especial por engano. Você deve validar o retorno da função de leitura e tratar o buffer do teclado (`stdin`) adequadamente.
4. **Consistência de Tipos:** Mantenha a atenção sobre a magnitude dos dados. A soma acumulada pode exigir tipos de maior capacidade que o contador de comprimento.