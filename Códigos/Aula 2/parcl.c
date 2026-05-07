main(){
    char n[30];
    float v, vf, vv;
    int p, pv;
    printf("Digite o nome do cliente: ");
    scanf("%s", &n);
    printf("Digite o valor total da compra: ");
    scanf("%f", &v);
    if(v < 0){
        vv = 1;
    }
    if (v == 0){
        vv = 2;
    }
    printf("Digite a quantidade de parcela: ");
    scanf("%i", &p);
    if(p < 1){
        pv = 1;
    }
    if(p > 12){
        pv = 2;
    }
    vf = v/p;

    if(vv == 1){
        printf("Erro: Valor negativo.\n");
    }
    if(vv == 2){
        printf("Erro: valor igual a zero.\n");
    }
    if(pv == 1){
        printf("Erro: Parcela menor que 1.\n");
    }
    if(pv == 2){
        printf("Erro: Parcela maior que 12.\n");
    }
    if(pv == 0 && vv == 0){
    printf("%s seu preco final sera %f", n, vf);
    }
}
