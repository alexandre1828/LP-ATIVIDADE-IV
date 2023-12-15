#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tam 3

    struct info_contatos
    {
        char nome[200][tam];
        char telefone[200][tam];
        char email[200][tam];


    };

    char* buscar(struct info_contatos contatos[],char* nome) {

        int i;

        for ( i = 0; i < tam; i++)
        {
            if (strcmp(contatos[i].nome,nome)== 0)
            {
                return contatos[i].telefone;
            }
            
        }
        

    }

    int main() {
        struct info_contatos contatos[tam];
        int i;
        char nome[200];

        for ( i = 0; i < tam; i++)
        {
           
            printf("%d contato \n",i + 1);
            printf("digite seu nome:");
            gets(contatos[i].nome);
            printf("digite seu numero de telefone:");
            gets(contatos[i].telefone);
            printf("digite seu email:");
            gets(contatos[i].email);

        }

        
        printf("Digite o nome do contato que deseja buscar: ");
        gets(nome);

        char* telefone = buscar(contatos,nome);

         printf("O número de telefone do contato %s é: %s\n", nome, telefone);


     return 0;   
    }
