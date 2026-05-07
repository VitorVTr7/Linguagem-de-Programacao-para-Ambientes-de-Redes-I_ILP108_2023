/* Desenvolver um programa em linguagem C que receba o valor bruto de salario do funcionario
e ao final calcule o valor INSS que sera descontado.
regra:
- acima de R$ 7.507,49 - será descontado o valor fixo de R$ 1.302,00.
- até R$ 1.302,00 - 7,5%
- de R$ 1.302,00 até R$ 2.571,29 - 9%
- de R$ 2.571,29 até R$ 3.856,94 - 12%
- de R$ 3.856,94 até R$ 7.507,49 - 14%

Ao final mostre o nome do funcionario, o seu valor bruto de salario, o valor do INSS
que sera descontado, e por fim, o valor do salario liquido.
*/

float calc_inss(float sal_bruto);

main(){
    char n[30];
    float vbruto, vinss, vliqui;
    int mensagem, continua;
    continua = 1;

    while(continua == 1){
    system("cls");
    printf("Coloque o nome do funcionario: ");
    scanf("%s", &n);
    printf("Coloque o valor bruto do seu salario: ");
    scanf("%f", &vbruto);

    vinss = calc_inss(vbruto);


    printf("Ola %s \n", n);
    printf("Seu salario bruto: %.2f \n", vbruto);
    printf("Valor do INSS: %.2f \n", vinss);
    printf("Valor do salario liquido: %.2f \n", (vbruto - vinss));
    printf("Continuar com o programa?(1 - Sim | 0 - Nao): ");
    scanf("%d",&continua);
    }
}


float calc_inss (float sal_bruto){
    float inss;
    if(sal_bruto > 0){
       if(sal_bruto <= 1302){
           inss = (sal_bruto / 100) * 7.5;
       }else if(sal_bruto > 1302 && sal_bruto <= 2571.29){
           inss = (sal_bruto /100) * 9;
       }else if(sal_bruto > 2571.29 && sal_bruto <= 3856.93){
           inss = (sal_bruto / 100) * 12;
       }else if(sal_bruto > 3856.94 && sal_bruto <= 7507.48){
           inss = (sal_bruto / 100) * 14;
       }else{
           inss = 1302;
       }
   }else{
       inss = -999;
   }

    return inss;
}
