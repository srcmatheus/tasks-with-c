#include <stdio.h>

#define TAM_HISTORICO 10
#define TAM_RESULTADO 10

int buscaLinearMultipla(const int *historico, int tamanho, int alvo, int *indicesEncontrados);

int main(){

    int alvo = 0;
    int verificador = 0;
    int resultado = 0;

    int historico[TAM_HISTORICO] = {150, 40, 200, 40, 90, 40, 300, 120, 40, 50};
    int indices[TAM_RESULTADO];

    
    printf("Digite o valor suspeito a ser rastreado: ");
    verificador = scanf("%d", &alvo);

    while(1){
        if(alvo < 0 || verificador == 0 || getchar() != '\n'){
            printf("Valor inválido. Digite novamente: ");
            while(getchar() != '\n');
            verificador = scanf("%d", &alvo);
        }else{
            break;
        }
    }

    resultado = buscaLinearMultipla(historico, TAM_HISTORICO, alvo, indices);

    if(resultado > 0){
        printf("O valor suspeito foi encontrado nos seguintes índices: ");
        for(int i = 0; i < resultado; i++) printf("%d ", indices[i]);
        printf("\nVezes que o valor apareceu: %d\n", resultado);
    }else{
        printf("Transação segura. Nenhum valor foi encontrado.\n");
    }
    return 0;
}

int buscaLinearMultipla(const int *historico, int tamanho, int alvo, int *indicesEncontrados){
    int contador = 0;

    for(int i = 0; i < tamanho; i++){
        if(alvo == historico[i]){
            indicesEncontrados[contador] = i;
            contador++;
        }
    }
    return contador;
}