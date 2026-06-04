#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int id;
    int ciclos;
    struct No *proximo;
} No;

void inserirOrdenado(No **head, int id, int ciclos);
void executarProximaTarefa(No ** head);
void liberarLista(No ** head);

int main(){

    No *head = NULL;

    int id;
    int ciclos;
    int verificador;

    while(1){
        printf("Digite o id: ");
        verificador = scanf("%d", &id);
        if(verificador == 0 || id < 0){
            printf("Valor inválido. ");
            while(getchar() != '\n');
            continue;
        }

        if(id == 0) break;

        printf("Digite o ciclo: ");
        verificador = scanf("%d", &ciclos);
        while(verificador == 0 || ciclos <= 0){
            printf("Valor inválido. Digite novamente: ");
            while(getchar() != '\n');
            verificador = scanf("%d", &ciclos);
        }

        inserirOrdenado(&head, id, ciclos);

    }
    printf("\033[H\033[J"); //Limpar terminal.
    executarProximaTarefa(&head);
    liberarLista(&head);
    return 0;
}

void inserirOrdenado(No **head, int id, int ciclos){

    No * novo = (No*) malloc(sizeof(No));

    if(novo == NULL){
        printf("Erro grave de memória...\n");
        return;
    }

    novo->id = id;
    novo->ciclos = ciclos;
    novo->proximo = NULL;

    No * anterior = NULL;
    No * atual = *head;

    while(atual != NULL && novo->ciclos > atual->ciclos){
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL){
        novo->proximo = *head;
        *head = novo;
    }else{
        anterior->proximo = novo;
        novo->proximo = atual;
    }

}

void executarProximaTarefa(No ** head){

    No * proximo;

    if(*head == NULL){
        printf("Nenhum ciclo foi encontrado...\n");
        return;
    }else{
        while(*head != NULL){
            printf("Executando Tarefa: ID %d (%d ciclos)...\n", (*head)->id, (*head)->ciclos);
            proximo = (*head)->proximo;
            free(*head);
            *head = proximo;
        }
    }

}

void liberarLista(No ** head){

    No * proximo;

    if(*head == NULL){
        printf("\nA lista já foi liberada com sucesso.\n");
    }else{
        while(*head != NULL){
            proximo = (*head)->proximo;
            free(*head);
            *head = proximo;
        }
        printf("\nLista liberada com sucesso!\n");
    }

}