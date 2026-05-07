/* - Desenvolver um sistema de conversão de graus celsiu p/ fahrenheit.
     Onde o sistema deve receber um valor real p/ medida de graus celsius que deve estar entre -32 à 480.
     Caso esteja nesse intervalo exibir qual seria o valor respectivo em fanrenheit.

        Fórmula:

        C x 9/5 + 32

     Ao final perguntar ao usuárui se quer realizar um novo cálculo.
*/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>



float conversaofanrenheit (float con_celsius);

int main(){
    int status = 1;
    float celsius, fanrenheit;

    while(status == 1){
    printf("Bem-vindo, usuario.\n\nEsse programa fara a conversao de temperatura, de graus celsius, para fanrenheit.\n\n");
    printf("Coloque a temperatura, em graus celsius: ");
    scanf("%f", &celsius);


    fanrenheit = conversaofanrenheit(celsius);
    system("cls");
    if(fanrenheit == -999 || fanrenheit == -998){
        printf("ERROR: Valor recebido fora do intervalo.");
    }else{
        printf("Aqui esta o sua temperatura, em fanrenheit: %.1f", fanrenheit);
    }
    printf("\n\nDeseja fazer a conversao novamente? (1 - Sim | 0 - Nao)\n");
    scanf("%d", &status);
    system("cls");
    }
    printf("PROGRAMA FINALIZADO. Tenha um otimo dia.\n");
}


float conversaofanrenheit (float con_celsius){
    if(con_celsius < -32){
        return -999;
    }else if(con_celsius > 480){
        return -998;
    }else{
        return ((con_celsius * 9) / 5) + 32;
}
}
