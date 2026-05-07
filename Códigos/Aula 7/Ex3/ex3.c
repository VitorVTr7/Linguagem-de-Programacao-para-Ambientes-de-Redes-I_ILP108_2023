/* Criar um vetor float de 50 posiçoes.
   O programa simula uma registradora de mercado.
   Primeiro perguntar ao usuário quantos produtos serão digitados.
   Depois receber os valores dos produtos e ao final mostrar o preço a ser pago . */


#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(){
    float vetor[50], somador, media;
    int quant, i;
    quant = 0;
    while(quant == 0 || quant > 50 || quant < 0){
    printf("Quantos produtos serao digitados? \nQuant.: ");
    scanf("%d", &quant);
    if(quant == 0){
        printf("Erro: Valor igual a zero. Tente novamente.\n\n");
    }else if(quant < 0){
        printf("Erro: Valor negativo. Tente novamente.\n\n");
    }else if(quant > 50){
        printf("Erro: Valor maior que 50. Tente novamente.\n\n");
    }

    }
    for(i = 0; i < quant; i++){
        system("cls");
        printf("Produto %d: ", (i + 1));
        scanf("%f", &vetor[i]);
        somador += vetor[i];
    }

    media = somador / quant;
    printf("Media: %.2f", media);
    return 0;

}
