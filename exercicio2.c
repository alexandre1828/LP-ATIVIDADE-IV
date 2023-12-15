#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tam 2

struct dados_aluno
{
    char nome[200];
    char data[200];
    int nota[2];
    float media;
};

float calcularmedia(int nota[])
{

    int i, j;
    float somanota = 0, media;

    for (j = 0; j < tam; j++)
    {
        somanota += nota[j];
    }

    media = somanota / tam;

    return media;
}


    char *situacao(float media){
    char situacao[200];
    if (media >= 7)
    {
        strcpy(situacao, "aprovado");
    } else
    {
         strcpy(situacao, "reprovado");
    }
    return situacao;
}

int main()
{
    struct dados_aluno aluno[5];
    int i, j;

    setlocale(LC_ALL, "portuguese");
   

    for (i = 0; i < 5; i++)
    {
        printf("%d ° aluno \n", i + 1);
        printf("digite o nome do aluno:");
        gets(aluno[i].nome);
        printf("data de nascimento:");
        gets(aluno[i].data);

        for (j = 0; j < 2; j++)
        {
            printf("digite %d nota ", j + 1);
            scanf("%d", &aluno[i].nota[j]);
        }

        aluno[i].media = calcularmedia(aluno[i].nota);

        printf("media: %.2f\n", aluno[i].media);
       
        fflush(stdin);
        printf("situacao: %s\n", situacao(aluno[i].media));
    }
        
     

    return 0;
}
