### 📦 Exercício 4: O Sistema de Telemetria de Conexão de Rede

**O Problema:**
Você está a desenvolver um módulo de baixo nível para um sistema operacional que monitoriza a qualidade de um socket de rede. Cada conexão possui três informações críticas: o identificador da conexão (`id`), o total de pacotes de dados transmitidos (`pacotes`) e a taxa de perda de pacotes expressa em percentagem (`perda`).

Sua tarefa é criar um programa modularizado que defina essa estrutura, inicialize os dados de uma conexão e, através de funções dedicadas, atualize o seu estado em tempo real com base no tráfego simulado.

**O Desafio Arquitetural:**
Você deve, obrigatoriamente, criar uma estrutura chamada `Conexao` e implementar a lógica dividida nas seguintes funções:

1. **Definição da Estrutura:**
```c
typedef struct {
    int id;
    int pacotes;
    double perda; // Em percentagem, ex: 2.5 para 2.5%
} Conexao;

```


2. `void simularTrafego(Conexao *c, int novosPacotes, int pacotesPerdidos)`
* Esta função recebe o endereço de uma estrutura `Conexao` via ponteiro.
* Ela deve atualizar o membro `pacotes` somando os `novosPacotes`.
* A função deve recalcular a nova taxa de `perda` acumulada com base na relação matemática:

$$\text{perda} = \left( \frac{\text{Total de Pacotes Perdidos}}{\text{Total de Pacotes Transmitidos}} \right) \times 100$$


* *Nota de Engenharia:* Você precisa acumular os perdidos e os transmitidos para recalcular de forma correta a percentagem global histórica. Pense em como fará isso utilizando apenas a estrutura fornecida e os parâmetros.


3. `void exibirRelatorio(const Conexao *c)`
* Esta função recebe a estrutura por ponteiro, mas com o modificador `const` (para garantir que a função seja **estritamente de leitura**, impedindo modificações acidentais nos dados).
* Ela deve exibir na tela os dados formatados da conexão.



**Fluxo de Execução na `main`:**

* A `main` deve inicializar uma `Conexao` (ex: `id = 101`, `pacotes = 0`, `perda = 0.0`).
* O programa deve ler do utilizador, em um laço `while`, blocos de telemetria contendo dois valores: `novos pacotes` e `quantos desses foram perdidos`.
* O laço encerra quando o utilizador digitar `-1` para o número de novos pacotes.
* A cada iteração válida, a função `simularTrafego` é chamada para atualizar o estado da struct.
* Ao encerrar, a função `exibirRelatorio` é disparada.

---

### ⚠️ Regras e Restrições de Engenharia (O Rigor)

1. **Uso Obrigatório do Operador de Seta (`->`):** Dentro das funções externas, o acesso aos membros da struct deve ser feito estritamente através da notação de ponteiro para estrutura (`ponteiro->membro`), e não por cópia de valor.
2. **Imutabilidade com `const`:** A função `exibirRelatorio` **deve** usar o modificador `const Conexao *c` na sua assinatura. Tentar modificar qualquer dado lá dentro deve gerar erro de compilação.
3. **Tratamento de Divisão por Zero:** No início da conexão, o total de pacotes é `0`. Certifique-se de que seu algoritmo de cálculo de perda está protegido contra divisões por zero se o utilizador inserir dados nulos na primeira iteração.
4. **Validação de Consistência:** É impossível perder mais pacotes do que a quantidade de novos pacotes transmitidos no bloco. Se o utilizador digitar que enviou 10 pacotes e perdeu 15, o programa deve acusar "Inconsistência de telemetria capturada", limpar o buffer e ignorar essa entrada específica.