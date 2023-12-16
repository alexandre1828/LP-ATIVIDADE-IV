#include<stdlib.h>
#include<locale.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[200];
    char cargo[200];
    float salario;
} Funcionario;

float mediaSalarial(Funcionario *funcionarios, char *cargo) {
    float somaSalarios = 0;
    int contador = 0;
    int i;
    for( i = 0; i < 5; i++) {
        if(strcmp((funcionarios + i)->cargo, cargo) == 0) {
            somaSalarios += (funcionarios + i)->salario;
            contador++;
        }
    }
    return somaSalarios / (float)contador;
}

int main() {

    setlocale(LC_ALL, "portuguese");

    Funcionario funcionarios[5];
    int i;
    char cargo[200];
    int opcao;
        
    for ( i = 0; i < 5; i++)
        {
            printf("%d ° funcionario \n", i + 1);
            printf("digite o nome do funcionario:");
            gets(funcionarios[i].nome);

            printf("digite o cargo do funcionario:");
            gets(funcionarios[i].cargo);

            printf("digite o salario do funcionario:");
            scanf("%f",&funcionarios->salario);
            fflush(stdin);

        }

        while(opcao != 2) {
        printf("1 - Calcular média salarial\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o cargo: ");
                scanf("%s", cargo);
                float media = mediaSalarial(funcionarios,cargo);
                printf("Média salarial dos %s: %.2f\n", cargo, media);
                break;
            case 2:
            
            default:
                printf("Opção inválida!\n");
        }
    }

    

    
    return 0;
}
