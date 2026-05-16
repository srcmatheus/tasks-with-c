#include <stdio.h>

int main(){

    long long int numero;
    long long int somaDePares = 0;
    int numeroIndividual;
    int maiorDigito = 0;

    printf("Digite um número que seja maior que 0: ");
    scanf("%lld", &numero);

    while(numero <= 0){
        printf("Número inválido (apenas inteiro positivo). Digite novamente : ");
        scanf("%lld", &numero);
    }

    while(numero > 0){
        numeroIndividual = numero % 10;
        numero /= 10;
        
        if(numeroIndividual % 2 == 0) somaDePares += numeroIndividual;
        if(maiorDigito < numeroIndividual) maiorDigito = numeroIndividual;

    }

    printf("Soma dos dígitos pares: %lld\n", somaDePares);
    printf("Maior dígito: %d\n", maiorDigito);

    return 0;
}

//NOTA: NUNCA confie em um input do utilizador.