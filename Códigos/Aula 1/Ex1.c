main(){
    char nome[30];
    float nota1, nota2, media;

    nota1 = 1;
    nota2 = 2;

    printf("Coloque o seu nome: ");
    scanf("%s", &nome);
    printf("Coloque a primeira nota: ");
    scanf("%f", &nota1);
    while (nota1 < 0 || nota1 > 10){
            printf("Erro: nota menor que zero, ou nota maior que 10. \n");
            printf("Coloque a primeira nota: ");
            scanf("%f", &nota1);
    }
    printf("Coloque a segunda nota: ");
    scanf("%f", &nota2);
    while (nota2 < 0 || nota2 > 10){
            printf("Erro: nota menor que zero, ou nota maior que 10. \n");
            printf("Coloque a segunda nota: ");
            scanf("%f", &nota2);
    }

    media = (nota1 + nota2) / 2;

    printf("Sua media sera: %f", media);
}/*man*/
