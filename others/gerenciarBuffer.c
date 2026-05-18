//Este código é apenas para demonstrar como tratar buffer de memória do teclado, evitando erros com entradas de usuários.

#include <stdio.h>

int main(){

    int num;
    int c = 5;

    while(c > 0){
        c--;
        printf("Digite um número: ");
            
        if(scanf("%d", &num) == 0){
            printf("Erro: você digitou um número inválido.\n");
            while(getchar() != '\n');
        }else{
            printf("O número digitado foi: %d\n", num);
        }

    }

    return 0;
}