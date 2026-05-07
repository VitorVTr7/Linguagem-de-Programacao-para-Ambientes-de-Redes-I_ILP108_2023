#include "stdio.h"
#include "conio.h"

main(){
    FILE *arquivo;

    char disciplina[30];
    int carga_horaria;
    float frequencia;
    int op = 1;

    arquivo = fopen("lista.txt", "w");

    while(op != 0){
        printf("disciplina: ");
        scanf("%s", &disciplina);
        printf("carga horaria: ");
        scanf("%i", &carga_horaria);
        printf("frequencia: ");
        scanf("%f", &frequencia);

        fprintf(arquivo, "%s;%i;%f;\n", disciplina, carga_horaria, frequencia);

        printf("sair? digite zero:");
        scanf("%i", &op);
    }

}
