#include <stdio.h>
#include <stdlib.h>

void adicionarLeitura(double **array, int *tamanhoAtual, int *capacidadeMaxima, double novoDado);

void exibirRelatorioEstatistico(const double *array, int tamanhoAtual, int capacidadeMaxima);

int main(){
    
    int verificador = 0;
    double temperatura = 0;

    int tamanhoAtual = 0;
    int capacidadeMaxima = 2;
    int *ponteiroParaAtual = &tamanhoAtual;
    int *ponteiroParaMaxima = &capacidadeMaxima;

    double *array = (double *) malloc(*ponteiroParaMaxima * sizeof(double));

    while(1){
        printf("Digite a temperatura: ");
        verificador = scanf("%lf", &temperatura);
        if(temperatura == -999.0) break;
        if(verificador == 0){
            printf("Valor inválido. ");
            while(getchar() != '\n');
            continue;
        }
        adicionarLeitura(&array, ponteiroParaAtual, ponteiroParaMaxima, temperatura );
        while(getchar() != '\n');
    }
    exibirRelatorioEstatistico(array, tamanhoAtual, capacidadeMaxima);
    free(array);
    return 0;
}

void adicionarLeitura(double **array, int *tamanhoAtual, int *capacidadeMaxima, double novoDado){
    
    if(*tamanhoAtual >= *capacidadeMaxima){
        int novaCapacidade = *capacidadeMaxima * 2;

        double *temp = (double *) realloc(*array, novaCapacidade * sizeof(double));
        
        if(temp == NULL){
            printf("Erro critico de memória");
            return;
        }
        *array = temp;
        *capacidadeMaxima = novaCapacidade;
    }
    
    (*array)[*tamanhoAtual] = novoDado;
    *tamanhoAtual += 1;
    
}

void exibirRelatorioEstatistico(const double *array, int tamanhoAtual, int capacidadeMaxima){
    double media = 0;

    for(int i = 0; i < tamanhoAtual; i++) media += array[i];

    media = media / tamanhoAtual;

    printf("\nA média atual de temperatura foi: %.1lf° graus.\n", media);
    printf("Armazenado %d elementos em um espaço alocado para %d elementos.\n", tamanhoAtual, capacidadeMaxima);
}