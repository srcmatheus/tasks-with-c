#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo{
    int id;
    struct NoDuplo * proximo;
    struct NoDuplo * anterior;
} NoDuplo;

typedef struct{
    NoDuplo * head;
    NoDuplo * tail;
    NoDuplo * atual;
} Historico;

void registrarAcao(Historico *h, int id);
void desfazer(Historico *h);
void refazer(Historico *h);
void limparHistorico(Historico *h);

void verificarDados(Historico *h);

int main(){

    Historico * cursor = (Historico*) malloc(sizeof(Historico));
    cursor->head = NULL;
    cursor->atual = NULL;
    cursor->tail = NULL;

    int acao = 0;
    int id = 100;

    printf("\nAÇÕES ===================================================================\n");
    printf("1 - Registrar | 2 - Desfazer | 3 - Refazer | 4 - Verificar | 0 - Encerrar\n");

    while(1){
        printf("\nDigite a ação: ");
        scanf("%d", &acao);

        switch(acao){
            case 1:
                id++;
                registrarAcao(cursor, id);
                break;
            case 2:
                desfazer(cursor);
                break;
            case 3:
                refazer(cursor);
                break;
            case 4:
                verificarDados(cursor);
                break;
            case 0:
                limparHistorico(cursor);
                printf("Saindo do programa...");
                return 0;
                break;
            default:
                printf("Comando inválido. ");
                while(getchar() != '\n');
                break;
        }
    }

    return 0;
}

void registrarAcao(Historico *h, int id){

    NoDuplo * novo = (NoDuplo*) malloc(sizeof(NoDuplo));

    if(novo == NULL){
        printf("Erro crítico na memória...");
        return;
    }

    novo->id = id;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if(h->atual != NULL && h->atual != h->tail){
        NoDuplo * aux = h->atual->proximo;
        while(aux != NULL){
            NoDuplo * proxAux = aux->proximo;
            free(aux);
            aux = proxAux;
        }
        h->tail = h->atual;
        h->tail->proximo = NULL;
    }

    if(h->head == NULL){
        h->head = novo;
        h->atual = novo;
        h->tail = novo;
    }else{
        novo->anterior = h->tail;
        novo->proximo = NULL;

        h->tail->proximo = novo;
        h->tail = novo;
        h->atual = novo;
    }

}

void desfazer(Historico *h){

    if(h->atual->anterior == NULL){
        printf("Não há ações para desfazer...");
    }else{
        h->atual = h->atual->anterior;
        printf("Undo executado. Estado atual: ID %d\n", h->atual->id);
    }

}

void refazer(Historico *h){

    if(h->atual->proximo == NULL){
        printf("Não há ações para desfazer...");
    }else{
        h->atual = h->atual->proximo;
        printf("Rede executado. Estado atual: ID %d\n", h->atual->id);
    }

}

void limparHistorico(Historico *h){
    NoDuplo * aux = h->head;
    while(aux != NULL){
        NoDuplo * proxAux = aux->proximo;
        free(aux);
        aux = proxAux;
    }
    printf("\nMemória liberada com sucesso! Programa encerrando...\n");
    free(h);
}

void verificarDados(Historico *h){
    NoDuplo * copia = h->head;
    if(copia == NULL){
        printf("Não há dados para verificar...");
    }else{
        while(copia != NULL){
            printf("ID: %d\n", copia->id);
            copia = copia->proximo;
        }
    }
}