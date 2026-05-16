### 🧱 Exercício 1: O Analisador Aritmético de Dígitos

**O Problema:**
Muitas vezes, em sistemas de criptografia de baixo nível ou compressão de dados, precisamos extrair propriedades matemáticas de fluxos numéricos brutos antes mesmo de os armazenar em estruturas complexas.

Sua tarefa é criar um algoritmo estruturado na função `main` que leia **um único número inteiro positivo** fornecido pelo utilizador e determine, usando exclusivamente lógica aritmética:

1. A **soma** de todos os dígitos individuais desse número que sejam **pares**.
2. O **maior dígito** isolado presente nesse número.

**Exemplo de Execução:**

* **Entrada:** `27438`
* **Processamento interno:** * Dígitos pares: $2, 4, 8 \implies \text{Soma} = 14$
* Todos os dígitos: $2, 7, 4, 3, 8 \implies \text{Maior} = 8$


* **Saída Esperada:**
`Soma dos digitos pares: 14`
`Maior digito: 8`

---

### ⚠️ Regras e Restrições de Engenharia (O Rigor)

1. 
**Proibição Absoluta de Vetores e Strings:** Está terminantemente proibido o uso de arrays (`char[]`, `int[]`) ou funções de bibliotecas de texto (como `<string.h>`). O número deve ser lido e processado numericamente através de laços de repetição e operadores aritméticos (`/` e `%`).


2. **Proteção contra Transbordamento (Overflow):** O utilizador pode inserir números de grande magnitude. Escolha com precisão o tipo primitivo adequado e a respetiva máscara de formatação no `scanf` e `printf` para garantir que o programa suporta inteiros massivos.


3. 
**Higiene de Código:** Declarações redundantes, variáveis não utilizadas ou falta de tratamento para entradas inválidas (ex: números negativos) reduzirão drasticamente a sua nota.


4. 
**Compilação Estrita:** O seu código deve ser escrito assumindo o padrão moderno e sem avisos no compilador (`-Wall -Wextra -std=c11`).
