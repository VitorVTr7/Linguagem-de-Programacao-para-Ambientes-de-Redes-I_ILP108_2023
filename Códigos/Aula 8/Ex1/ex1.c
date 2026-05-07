#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(){
    int indice;

    struct molde_pessoa{
        char nome[30];
        int idade;
        float salario;
    };
    struct molde_pessoa pessoa[3];

    for(indice = 0; indice < 3; indice++){
        system("cls");
        printf("Pessoa %i \n\n", (indice+1));
        printf("Digite o nome de pessoa: ");
        scanf("%s", &pessoa[indice].nome);
        printf("Digite o idade de pessoa: ");
        scanf("%i", &pessoa[indice].idade);
        printf("Digite o salario de pessoa: ");
        scanf("%f", &pessoa[indice].salario);
    }

    printf("\n\n");
    for(indice = 0; indice < 3; indice++){
        printf("Pessoa %d :: Nome: %s :: Idade: %d :: Salario: %f\n\n", (indice+1), pessoa[indice].nome, pessoa[indice].idade, pessoa[indice].salario);
    }
}
