#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id_documento;
    char nome_arquivo[50];
    struct Node *proximo;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
} FilaImpressao;

void enqueue(FilaImpressao *f, int id, const char *nome);
void dequeue(FilaImpressao *f);
void limparFila(FilaImpressao *f);

int main(){

    FilaImpressao * fila = (FilaImpressao*) malloc(sizeof(FilaImpressao));
    fila->inicio = NULL;
    fila->fim = NULL;

    int id = 100;
    char opcao[50];
    char nome[50];

    printf("MENU ===============================\n");
    printf("Seleciona uma opção:\n");
    printf("1 - novo | 2 - imprimir | 3 - fechar\n");
    printf("====================================\n");

    while(1){

        printf("Opção: ");
        fgets(opcao, sizeof(opcao), stdin);

        if(strchr(opcao, '\n') == NULL){
            printf("Limite de caracteres atingido. Digite novamente. ");
            while(getchar() != '\n');
            continue;
        }

        switch(opcao[0]){
            case '1':
                sscanf(opcao, "%*d %s", nome);
                if(nome[0] == '\0'){
                    printf("O nome do arquivo não foi digitado. Tente novamente. ");
                    continue;
                }
                id++;
                enqueue(fila, id, nome);
                nome[0] = '\0';
                break;
            case '2':
                dequeue(fila);
                break;
            case '3':
                limparFila(fila);
                free(fila);
                return 0;
                break;
            default:
                printf("Opção inválida, digite novamente. ");
                break;
        }
    }
    return 0;
}

void enqueue(FilaImpressao *f, int id, const char *nome){

    Node * novo = (Node*) malloc(sizeof(Node));

    if(novo == NULL){
        printf("Erro grave de memória...");
        return;
    }

    novo->id_documento = id;
    strcpy(novo->nome_arquivo, nome);
    novo->proximo = NULL;

    if(f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->proximo = novo;
        f->fim = novo;
    }
}

void dequeue(FilaImpressao *f){
    if(f->inicio == NULL){
        printf("Fila de impressão vazia.\n");
    }else{
        Node * salvar = f->inicio;
        printf("Imprimindo: [ID %d] - Arquivo: %s\n", f->inicio->id_documento, f->inicio->nome_arquivo);
        f->inicio = f->inicio->proximo;
        free(salvar);
    }

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
}

void limparFila(FilaImpressao *f){
    if(f->inicio == NULL){
        printf("A fila já está vazia. Encerrando programa...\n");
        return;
    }else{
        Node * salvar = f->inicio;
        while(salvar != NULL){
            Node *proximo = salvar->proximo;
            free(salvar);
            salvar = proximo;
        }

        f->inicio = NULL;
        f->fim = NULL;
        printf("A fila foi limpa.\n");
    }
}