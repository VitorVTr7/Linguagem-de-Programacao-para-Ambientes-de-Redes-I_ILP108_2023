main(){
    char nome[30];
    float nota1, nota2, media;

    nota1 = 1;
    nota2 = 2;

    printf("Coloque o seu nome: ");
    scanf("%s", &nome);
    printf("Coloque a primeira nota: ");
    scanf("%f", &nota1);
    printf("Coloque a segunda nota: ");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;

    if(nota1 >= 0 && nota1 <= 10 && nota2 >= 0 && nota2 <= 10){
        printf("A media: %f", media);
    }else{
        printf("Verefique as notas, media errada");
        }
}/*main*/
