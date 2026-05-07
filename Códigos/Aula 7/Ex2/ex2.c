/* Crie um programa que receba a idade de 8 pessoas e ao final mostre a média de idade dessas pessoas. */


#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(){
    int idade[8], i, somador;
    float media;

    for(i = 0; i < 8; i++){
        system("cls");
        printf("Coloque idade %d: ", (i + 1));
        scanf("%d", &idade[i]);
        somador += idade[i];
    }
    media = somador / 8;
    printf("Idade media: %.f\n", media);
    return 0;
}
