//Binary Search é um algoritmo de busca utilizado em listas ordenadas.

#include <stdio.h>

int main(){

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int menorValor = 0;
    int maiorValor = 9;
    int meio = (menorValor + maiorValor) / 2;

    int valorSugerido;
    int valorBuscado = 7;
    
    while(menorValor <= maiorValor){
        meio = (menorValor + maiorValor) / 2;
        valorSugerido = array[meio];

        if(valorSugerido == valorBuscado){
            printf("Posição do valor encontrado: %d\n", meio);
            return 0;
        }

        if(valorSugerido > valorBuscado){
            maiorValor = meio - 1;
        }else{
            menorValor = meio + 1;
        } 
    }

    printf("Valor não encontrado...");

    return 0;
}