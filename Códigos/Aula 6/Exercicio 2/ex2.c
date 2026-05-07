/*
    -Desenvolver uma funçao que receba os parametros: total da dívida e quantidade de parcelas.

    -Tratar o total da dívida: se for 0 (zero) ou menor que zero, retornar -999.

    -Tratar a quantidade de parcelas se for menor ou igual a zero retornar -998.

*/

#include <stdlib.h>
#include <stdio.h>

float calculoparcela (float cal_divida, int cal_parcela);

int main(){
    int parcela = 12;
    float divida = 4889.90;

    printf("R$ %.2f", calculoparcela(divida, parcela));

    return 0;
}

float calculoparcela (float cal_divida, int cal_parcela){

    if(cal_divida <= 0){
        return -999;
    }else if(cal_parcela <= 0){
        return -998;
    }else{
        return cal_divida / cal_parcela;
    }
}

