#include <stdio.h>

int main(){

    int verificador;
    int comprimento = 0;
    int maiorSubsequencia = 0;
    long long int numero = 1;
    long long int digitoAnterior;
    long long int somaSubsequenciaAtual = 0;
    long long int somaMaiorSubsequencia = 0;

    while(numero > 0){

        digitoAnterior = numero;

        printf("\nDigite um número inteiro:");
        verificador = scanf("%lld", &numero);

        if(numero == 0) return 0;

        while(numero < 0 || verificador == 0){
            printf("\nValor inválido. Digite um número inteiro positivo: ");
            while(getchar() != '\n');
            verificador = scanf("%lld", &numero);
        }

        if(numero > digitoAnterior){
            comprimento++;
            somaSubsequenciaAtual += numero;
        }else{
            comprimento = 1;
            somaSubsequenciaAtual = numero;
        }

        if(comprimento > maiorSubsequencia){
            maiorSubsequencia = comprimento;
            somaMaiorSubsequencia = somaSubsequenciaAtual;
        }else if(comprimento == maiorSubsequencia && somaMaiorSubsequencia < somaSubsequenciaAtual){
            somaMaiorSubsequencia = somaSubsequenciaAtual;
        }

    }

    printf("\nMaior subsequencia crescente: %d elemento(s).\n", maiorSubsequencia);
    printf("Soma da maior subsequencia: %lld\n", somaMaiorSubsequencia);

    return 0;
}