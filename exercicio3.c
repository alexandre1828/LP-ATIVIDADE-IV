#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

float valorTotalEmEstoque(Produto *produto) {
    return produto->preco * produto->quantidade;
}

void atualizarQuantidadeEmEstoque(Produto *produto, int quantidadeComprada) {
    produto->quantidade -= quantidadeComprada;
}

int main() {
    
    setlocale(LC_ALL, "portuguese");

    Produto produto;
    int opcao, quantidadeComprada;

    while(1) {
        printf("1 - Adicionar produto\n");
        printf("2 - Realizar uma compra\n");
        printf("3 - Consultar estoque\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Nome do produto: ");
                scanf("%s", produto.nome);
                printf("Preço do produto: ");
                scanf("%f", &produto.preco);
                printf("Quantidade em estoque: ");
                scanf("%d", &produto.quantidade);
                break;
            case 2:
                printf("Quantidade comprada: ");
                scanf("%d", &quantidadeComprada);
                atualizarQuantidadeEmEstoque(&produto, quantidadeComprada);
                break;
            case 3:
                printf("Valor total em estoque: %.2f\n", valorTotalEmEstoque(&produto));
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
