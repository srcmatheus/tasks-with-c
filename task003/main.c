#include <stdio.h>
#include <math.h>

void processarMovimento(int movimento, int * px, int * py);
double calcularDistanciaOrigem(int x, int y);

int main() {
    
    int movimento = 1;
    int verificador;
    int x = 0, y = 0;   
    int * px = &x;
    int * py = &y;
    
    printf("===================GRID NAVIGATION=====================\n");
    printf("1 para Norte | 2 para Sul | 3 para Leste | 4 para Oeste\n");
    printf("-------------------------------------------------------\n");
    
    while(movimento != 0){
        printf("Digite a direção: ");
        verificador = scanf("%d", &movimento);
        
        while(movimento < 0 || movimento > 4 || verificador == 0){
            printf("Digite um valor válido: ");
            while(getchar() != '\n');
            verificador = scanf("%d", &movimento);
        }
        processarMovimento(movimento, px, py);
    }
    printf("\nA distância percorrida foi de %.2lf metros\n", calcularDistanciaOrigem(x, y));
    return 0;
}

void processarMovimento(int movimento, int *px, int *py){
    switch(movimento){
        case 1:
            *py += 1;
            break;
        case 2:
            *py -= 1;
            break;
        case 3:
            *px += 1;
            break;
        case 4:
            *px -= 1;
            break;
    }
}

double calcularDistanciaOrigem(int x, int y){
    int a = x;
    int b = y;
    double resultado;
    a *= x;
    b *= y;
    resultado = sqrt(a + b);
    return resultado;
}