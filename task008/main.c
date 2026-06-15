#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char simbolo;
    struct Node * proximo;
} Node;

void push(Node **topo, char c);
char pop(Node **topo);
void limparPilha(Node **topo);

int main(){

    Node * verificador = NULL;
    char entrada[100];

    printf("Digite uma operação matemática ou um código: ");
    fgets(entrada, 100, stdin);

    for(int i = 0;;i++){

        char digito = '\0';
        char correspondente = '\0';

        if(entrada[i] == '\0') break;

        if(entrada[i] == '(' || entrada[i] == '{' || entrada[i] == '[') push(&verificador, entrada[i]);

        if(entrada[i] == ')' || entrada[i] == '}' || entrada[i] == ']'){
            digito = pop(&verificador);

            switch(entrada[i]){
                case ')':
                    correspondente = '(';
                    break;
                case ']':
                    correspondente = '[';
                    break;
                case '}':
                    correspondente = '{';
                    break;
                default:
                    break;
            }

            if(correspondente != digito){
                printf("Erro de escopo...\n");
                limparPilha(&verificador);
                return 0;
            }
        }
    }

    if(verificador != NULL){
        printf("Erro de sintaxe...\n");
    }else{
        printf("Seu código está limpo!\n");
    }

    limparPilha(&verificador);
    return 0;
}

void push(Node **topo, char c){
    Node * novo = (Node*) malloc(sizeof(Node));

    if(novo == NULL){
        printf("Erro grave de memória...");
        return;
    }

    novo->simbolo = c;
    novo->proximo = *topo;
    *topo = novo;
}

char pop(Node **topo){
    Node * atual = *topo;

    if(atual == NULL){
        return '\0';
    }else{
        char caractere = atual->simbolo;
        *topo = atual->proximo;
        free(atual);
        return caractere;
    }
}

void limparPilha(Node **topo){
    Node * lista = *topo;
    Node * save;

    while(lista != NULL){
        save = lista->proximo;
        free(lista);
        lista = save;
    }
}