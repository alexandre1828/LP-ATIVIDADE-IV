#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct info_contabancaria
{
     int numero;
    char titular[200];
    float saldo;
    char tipo[200];  
};

void depositar(struct info_contabancaria *conta, float valor) {
conta->saldo += valor;
}

void sacar(struct info_contabancaria *conta, float valor) {
    if(valor > conta->saldo) {
        printf("Saldo insuficiente!\n");
    } else {
        conta->saldo -= valor;
    }
}
void imprimirSaldo(struct info_contabancaria *conta) {
    printf("Saldo atual: %.2f\n", conta->saldo);
}
 
int main() {

    setlocale(LC_ALL, "portuguese");

    struct info_contabancaria conta;
    int opcao;
    float valor;

    printf("Número da conta: ");
    scanf("%d", &conta.numero);
    printf("Nome do titular: ");
    scanf("%s", conta.titular);
    printf("Tipo de conta (poupança ou corrente): ");
    scanf("%s", conta.tipo);
    conta.saldo = 0;

    while (1)
    {
       printf("1 - Depositar dinheiro\n");
        printf("2 - Sacar dinheiro\n");
        printf("3 - Imprimir saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); 

        switch(opcao) {
            case 1:
                printf("Valor a depositar: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Valor a sacar: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                imprimirSaldo(&conta);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
