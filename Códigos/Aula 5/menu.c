#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


float calculo_autonomia(float tanqueauto, float conslitroauto);

float calculo_consumo(float kmcon, float litrocons);

float calculo_abastecimento(float tamanhotanqabas, float presentetanqabas, float precoabas);


int main(){

    int op = 1;
    float km, litro, tanquelitro, consumolitro, tamanhotanq, presentetanque, precocombu, consumo, autonomia, precofinal;

    while(op != 0){
        system("cls");
        printf("Ola usuario. \n");
        printf("Selecione uma das seguintes opcao, para que ocorra o calculo desejado: \n");
        printf("\n 1 - Autonomia do veiculo;");
        printf("\n 2 - Consumo do veiculo;");
        printf("\n 3 - Abastecimento do veiculo;");
        printf("\n 0 - Sair.");
        printf("\n \n Digite a opcao: ");
        scanf("%i", &op);

        if(op == 1){
            system("cls");
            printf("OPCAO 1 \n \n");
            printf("Quantidade de litros do tanque de combustivel: ");
            scanf("%f", &tanquelitro);
            printf("\nQuantidade do consumo(km/l): ");
            scanf("%f", &consumolitro);
            autonomia = calculo_autonomia(tanquelitro, consumolitro);
            if(autonomia == -999){
                printf("\nError: Valor de litros do tanque tem que ser maior que 0.\n");
            }else if(autonomia == -998){
                printf("\nError: Valor do consumo tem que ser maior que 0.\n");
            }else{
                printf("Valor do sua autonomia sera: %.2f", autonomia);
            }
            printf("\nDigite p/ continuar...");
            getch();

        }else if(op == 2){
            system("cls");
            printf("OPCAO 2 \n \n");
            printf("Quantidade de Kilometros percorridos: ");
            scanf("%f", &km);
            printf("\nQuantidade de Litros consumidos: ");
            scanf("%f", &litro);
            consumo = calculo_consumo(km, litro);
            if(consumo == -999){
                printf("\nError: Valor do kilometro tem que ser maior que 0.\n");
            }else if(consumo == -998){
                printf("\nError: Valor do litros consumidos tem que ser maior que 0.\n");
            }else{
                printf("Valor do seu consumo sera: %.2f", consumo);
            }
            printf("\nDigite p/ continuar...");
            getch();

        }else if(op == 3){
            system("cls");
            printf("OPCAO 3 \n \n");
            printf("Tamanho do tanque: ");
            scanf("%f", &tamanhotanq);
            printf("\nQuantos litros esta presente no seu tanque: ");
            scanf("%f", &presentetanque);
            printf("\nPreco do combustivel: ");
            scanf("%f", &precocombu);
            precofinal = calculo_abastecimento(tamanhotanq, presentetanque, precocombu);
            if(precofinal == -999){
                printf("\nError: Valor do tamanho do tanque tem que ser maior que 0.");
            }else if(precofinal == -998){
                printf("\nError: Valor do litros presente no tanque tem que ser maior que 0, ou valor de litros presente maior que o valor do tanque.");
            }else if (precofinal == -997){
                printf("\nError: Valor do preco do combustivel tem que ser maior que 0.");
            }else{
                printf("\nValor do preco a ser pago: R$%.2f", precofinal);
            }

            printf("\nDigite algo para continuar...");
            getch();

        }else if(op == 0){
            system("cls");
            printf("Obrigado!!!");

        }else{
            system("cls");
            printf("Opcao invalida!");
            printf("\n digite algo p/ continuar...");
            getch();
        }
    }/*while*/
}/*mam*/

float calculo_autonomia(float tanqueauto, float conslitroauto){
    if(tanqueauto <= 0){
        return -999;
    }else if(conslitroauto <= 0){
        return -998;
    }else{
        return tanqueauto * conslitroauto;
}

}

float calculo_consumo(float kmcon, float litrocons){
    if(kmcon <= 0){
        return -999;
    }else if(litrocons <= 0){
        return -998;
    }else{
        return kmcon / litrocons;
    }
}

float calculo_abastecimento(float tamanhotanqabas, float presentetanqabas, float precoabas){
    if(tamanhotanqabas <= 0){
        return -999;
    }else if(presentetanqabas <= 0 || presentetanqabas > tamanhotanqabas){
        return -998;
    }else if(precoabas <= 0){
        return -997;
    }else{
        return (tamanhotanqabas - presentetanqabas) * precoabas;
    }
}




