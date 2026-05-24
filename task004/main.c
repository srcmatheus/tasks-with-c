#include <stdio.h>

typedef struct{
    int id;
    int pacotes;
    double perda;
} Conexao;

void simularTrafego(Conexao *c, int novosPacotes, int pacotesPerdidos);
void exibirRelatorio(const Conexao *c);

int main(){

    int verificador = 0;
    int novosPacotes = 0;
    int pacotesPerdidos = 0;

    Conexao novaConexao = {0, 0, 0};
    Conexao *ponteiroConexao = &novaConexao;

    while(novosPacotes >= 0){
        printf("\nNOVA CONEXÃO =============================================================================\n");

        //===================================================================================================
        printf("Quantidade de pacotes: ");
        verificador = scanf("%d", &novosPacotes);
        if(novosPacotes < 0) continue;
        if(verificador == 0){
            printf("Valor de pacote inválido. Digite novamente.");
            while(getchar() != '\n');
            continue;
        }

        printf("Pacotes perdidos: ");
        verificador = scanf("%d", &pacotesPerdidos);
        while(pacotesPerdidos > novosPacotes || pacotesPerdidos < 0 || verificador == 0){
            printf("Inconsistência de telemetria capturada. Digite os pacotes perdidos novamente: ");
            while(getchar() != '\n');
            verificador = scanf("%d", &pacotesPerdidos);
        }
        //===================================================================================================

        printf("Conexão encerrada.");
        printf("\n==========================================================================================\n");
        simularTrafego(ponteiroConexao, novosPacotes, pacotesPerdidos);
    }

    printf("Conexão encerrada.");
    printf("\n==========================================================================================\n");
    exibirRelatorio(ponteiroConexao);
    return 0;
}

void simularTrafego(Conexao *c, int novosPacotes, int pacotesPerdidos){
    c->id += 1;
    
    if(novosPacotes == 0){
        c->perda += 0;
    }else if(c->pacotes == 0){
        c->pacotes = novosPacotes;
        c->perda = ((double)pacotesPerdidos / novosPacotes) * 100;
        return;
    }else{
        c->perda = ((((c->perda * c->pacotes) / 100) + pacotesPerdidos) / (c->pacotes + novosPacotes)) * 100;
        c->pacotes += novosPacotes;
    }
}

void exibirRelatorio(const Conexao *c){
    printf("\n==================RELATÓRIO==================\n");
    printf("Total de conexões realizadas: %d\n", c->id);
    printf("Total de pacotes enviados: %d\n", c->pacotes);
    printf("Porcentagem de perda de pacotes: %.2lf%%\n", c->perda);
    printf("Total de pacotes transmitidos: %.0f\n", c->pacotes - (c->pacotes * (c->perda / 100)));
    printf("=============================================\n");
}