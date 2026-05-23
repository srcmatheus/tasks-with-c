Makefile é um arquivo que automatiza seu projeto. Invés de perder tempo digitando comandos de compilação, você pode simplesmente automatizar e economizar tempo. A principal função do Makefile é gerenciar a compilação do seu projeto, agrupando sequências complexas de comandos no terminal e realizando uma compilação incremental, que compila apenas arquivos que foram modificados, invés de recompilar todo o projeto. Em termos simples: em vez de você digitar comandos longos e repetitivos no terminal para compilar o seu código toda vez que fizer uma alteração, o Makefile faz isso por você com um único comando.

---

# Sintaxe
```
alvo: requisitos
	comando
```
- **Alvo (Target)**: geralmente é o nome do arquivo que você quer gerar, ou o nome de uma ação a ser executada.
- **Requisitos (Dependencies/Prerequisites)**: os arquivos necessários para criar o alvo. Se algum deles for mais recente que o alvo, o make sabe que precisa rodar os comandos novamente.
- **Comando (Command)**: linha de comando que será executada no terminal.

> Todo comando precisa ser precedido de um TAB. Se caso usar espaços, o arquivo irá quebrar.

## Exemplo completo

```
# 1. Definição de Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = meu_programa
LDLIBS = -lm

# 2. Regra Principal (Alvo Padrão)
all: $(TARGET)

# 3. Regra para gerar o executável
$(TARGET): main.o funcoes.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o funcoes.o

# 4. Regras para gerar os arquivos objeto (.o)
main.o: main.c funcoes.h
	$(CC) $(CFLAGS) -c main.c

funcoes.o: funcoes.c funcoes.h
	$(CC) $(CFLAGS) -c funcoes.c

# 5. Regra de Limpeza
clean:
	rm -f *.o $(TARGET)

# 6. Proteção contra conflitos de nomes
.PHONY: all clean
```

- ``CC = gcc``: define o compilador de C a ser utilizado.
- ``CFLAGS = -wall -Wextra -std=c99``: passa opções para o compilador. -Wall e -Wextra ativam alertas (warnings) que te ajudam a achar erros no código; -std=c99 define que estamos usando o padrão C99.
- ``TARGET = meu_programa``: nome final do arquivo executável.
- ``LDLIBS = -lm``: variável padrão para bibliotecas que serão linkadas. Nesse caso é específico para a lib `math.h`.

> Obs: para usar as variáveis, envolvemos em ``$(...)``.

### Alvo padrão

Por padrão, quando você digita apenas ``make`` no terminal, ele executa a primeira regra que encontrar. É uma convenção universal.

### Código fonte para objeto
```
main.o: main.c funcoes.h
	$(CC) $(CFLAGS) -c main.c
```
- transforma o arquivo de texto ``.c`` em um arquivo binário ``.o`` (código de máquina, mas que ainda não é um executável).
- a flag ``-c`` é crucial para dizer ao compilador para não gerar o executável.

### Limpeza
```
clean:
	rm -f *.o $(TARGET)
```
- realiza a limpeza apagando todos os arquivos ``.o`` e o executável para que seja possível uma compilação 100% limpa do zero.
- ``rm -f`` apaga os arquivos de forma forçada e não exibe alertas.

### PHONY
``.PHONY: all clean``
- os alvos são marcados como falso (apenas uma ação) e não como arquivos físicos. É utilizado para executar comandos sem a necessidade de um arquivo. Também serve para evitar conflitos com nomes de outros arquivos.

---

Adicionar um @ antes de cada comando o deixa "silencioso" e então não será exibido no terminal.
```
clean:
	@echo "Limpando os arquivos temporários..."
	@rm -f *.o $(TARGET)
```

---

### Variáveis automáticas
```
# Em vez de: meu_programa: main.o funcoes.o
#               gcc main.o funcoes.o -o meu_programa

meu_programa: main.o funcoes.o
	gcc $^ -o $@
```
- `$@`: Substitui pelo nome do Alvo atual.
- `$^`: Substitui por todas as Dependências.