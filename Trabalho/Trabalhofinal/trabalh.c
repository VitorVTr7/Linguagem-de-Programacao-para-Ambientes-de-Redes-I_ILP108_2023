/*Criar um programa com menu, que cada opção deverá ter os seguintes requesitos:

        1 - INCLUIR || VARIAVEL: NOME / IDADE / SALARIO
        2 - LISTAR  || DEMONSTRAR NUMA LISTA: NOME / IDADE / SALARIO
        3 - ALTERAR || ALTERAR O VALORES QUE FORAM COLOCADOS NO "INCLUIR"
        4 - APAGAR  || APAGAR UMA COLUNA DA MATRIZ

        0 - SAIR    || FECHARA O PROGRAMA

   O numero maximo de pessoas = 10
*/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

struct tabela_pessoas{
    char nome[30];
    int idade;
    float salario;
};

struct tabela_pessoas entrada[10];

void incluir(int incluir_pessoas){
    //PF INCLUIR VERIFICAÇÃO DE ERROS :(
    int verif_error = 1;
    while(verif_error == 1){
    printf("Pessoa %d\n", (incluir_pessoas + 1));
    printf("Inserir NOME: ");
    scanf("%s", &entrada[incluir_pessoas].nome);
    printf("Inserir IDADE: ");
    scanf("%d", &entrada[incluir_pessoas].idade);
    printf("Inserir SALARIO: ");
    scanf("%f", &entrada[incluir_pessoas].salario);
    //CHECAR ERRO
    if(entrada[incluir_pessoas].idade < 0){
        printf("ERRO: IDADE NEGATIVA\nTente novamente...\n\n");
        printf("precione qualquer tecla para continuar...");
        getch();
        system("cls");
    }else if(entrada[incluir_pessoas].salario < 0){
        printf("ERRO: SALARIO NEGATIVO\nTente novamente...\n\n");
        printf("pressione qualquer tecla para continuar...");
        getch();
        system("cls");
    }else{
        verif_error = 0;
    }
    }
}

void listar(int total){
    int i;
    total++;
    system("cls");
    printf("Pessoa         Nome       Idade        Salario\n");
    for(i = 0; i < total; i++){
       printf("%    3d %15s%12d%15.2f       \n", (i + 1), entrada[i].nome, entrada[i].idade, entrada[i].salario);
}
}

void alterar (int alterar_pessoas){
    int escolha, alterar_loop = 1, escolha_alteracao;
    alterar_pessoas += 2;
    while(alterar_loop == 1){
    system("cls");
    listar((alterar_pessoas - 2));
    printf("\n\nQual PESSOA deseja alterar?\n\n ");
    printf("PESSOA: ");
    scanf("%d", (&escolha));
    printf("\n\nQual valor deseja alterar?(1 - Nome | 2 - Idade | 3 - Salario | 4 - Todos os anteriores)\n\n");
    printf("Opcao: ");
    scanf("%d", &escolha_alteracao);
    if(escolha < alterar_pessoas && escolha > 0){
        if(escolha_alteracao == 1 || escolha_alteracao == 2 || escolha_alteracao == 3 || escolha_alteracao == 4){
        escolha -= 1;
        system("cls");
        printf("PESSOA %d (ORIGINAL):\n\n", (escolha + 1));
        printf("NOME: %s\n", entrada[escolha].nome);
        printf("IDADE: %d\n", entrada[escolha].idade);
        printf("SALARIO: %.2f\n\n", entrada[escolha].salario);
        if(escolha_alteracao == 1 || escolha_alteracao == 4){
        printf("NOME: ");
        scanf("%s", &entrada[escolha].nome);
        }
        if(escolha_alteracao == 2 || escolha_alteracao == 4){
        printf("IDADE: ");
        scanf("%d", &entrada[escolha].idade);
        }
        if(escolha_alteracao == 3 || escolha_alteracao == 4){
        printf("SALARIO: ");
        scanf("%f", &entrada[escolha].salario);
        }
        alterar_loop = 0;
        }else{
            printf("OPCAO INVALIDA.\n\n");
            printf("pressione qualquer tecla para continuar...");
            getch();
        }
    }else{
        printf("PESSOA INVALIDA.\n\n");
        printf("pressione qualquer tecla para continuar...");
        getch();
    }
    }
}

int apagar(int total_pessoas){
    int i_apagar, pessoa_desloca, loop_apagar = 1;

    while(loop_apagar == 1){
    listar(total_pessoas);
    printf("\n\nQual PESSOA deseja apagar?");
    printf("\nPESSOA: ");
    scanf("%d", &pessoa_desloca);
    pessoa_desloca--;
    if(pessoa_desloca < 0 || pessoa_desloca > total_pessoas ){
        printf("\n VALOR INVALIDO.");
        printf("\npressione qualquer coisa para continuar...");
        getch();
    }else{
        for(i_apagar = pessoa_desloca; i_apagar < total_pessoas; i_apagar++){
            strcpy(entrada[i_apagar].nome, entrada[i_apagar + 1].nome);
            entrada[i_apagar].idade = entrada[i_apagar + 1].idade;
            entrada[i_apagar].salario = entrada[i_apagar + 1].salario;
        }
        system("cls");
        printf("OPERACAO CONCLUIDA\n\n");
        printf("\npressione qualquer coisa para continuar...");
        getch();
        return total_pessoas;
    }
    }
}

void salvar(int salvar_pessoas){
    FILE *salvar_arquivo;
    int j;

    salvar_arquivo = fopen("lista.txt", "w");
    for(j = 0; j < salvar_pessoas; j++){
        fprintf(salvar_arquivo, "%s %d %.2f",entrada[j].nome, entrada[j].idade, entrada[j].salario);
        if(j != (salvar_pessoas - 1)){
            fprintf(salvar_arquivo, "\n");
        }
    }
    fclose(salvar_arquivo);

}

int leitura(int leitura_pessoas){
    FILE *leitura_arquivo;

    leitura_arquivo = fopen("lista.txt", "r");
    if(leitura_arquivo == NULL){
        return 0;
    }

    while(!feof(leitura_arquivo)){
        fscanf(leitura_arquivo,"%s ", entrada[leitura_pessoas].nome);
        fscanf(leitura_arquivo,"%d ", &entrada[leitura_pessoas].idade);
        fscanf(leitura_arquivo,"%f", &entrada[leitura_pessoas].salario);
        leitura_pessoas++;
        }

    fclose(leitura_arquivo);
    return leitura_pessoas;
}

int main(){
    int menu, menu_loop = 1, ciclo_pessoas = 0;
    ciclo_pessoas = leitura(ciclo_pessoas);
    while(menu_loop == 1){
        printf("Bem vindo, escolha uma das seguintes opcoes:\n\n");
        printf(" 1 - INCLUIR;\n");
        printf(" 2 - LISTAR;\n");
        printf(" 3 - ALTERAR;\n");
        printf(" 4 - APAGAR;\n");
        printf("\n 0 - SAIR.\n\n");
        printf("OPCAO: ");
        scanf("%d", &menu);
        if(menu == 1){
        if(ciclo_pessoas < 10){
          system("cls");
          incluir(ciclo_pessoas);
          system("cls");
          ciclo_pessoas++;
        }else{
            printf("LIMITE DE 10 PESSOAS ATINGINDA");
            printf("\npressione qualquer tecla para continuar...");
           getch();
           system("cls");
        }
        }else if(menu == 2){
        if(ciclo_pessoas > 0){
          listar((ciclo_pessoas - 1));
          printf("\n\npressione qualquer tecla para continuar...");
          getch();
          system("cls");
        }else{
          system("cls");
          printf("Lista Vazia.\n\n");
          printf("pressione qualquer tecla para continuar...");
          getch();
          system("cls");
        }
        }else if(menu == 3){
          if(ciclo_pessoas > 0){
             alterar(ciclo_pessoas - 1);
             system("cls");
          }else{
              system("cls");
              printf("Dados Inexistente.\n");
              printf("pressione qualquer tecla para continuar...");
              getch();
              system("cls");
          }
        }else if(menu == 4){
             if(ciclo_pessoas > 0){
             ciclo_pessoas = apagar(ciclo_pessoas - 1);
             system("cls");
             }else{
             system("cls");
             printf("Dado Inexistente.\n");
             printf("pressione qualquer tecla para continuar...");
             getch();
             system("cls");
             }

        }else if(menu == 0){
          if(ciclo_pessoas > 0){
            salvar(ciclo_pessoas);
          }
          system("cls");
          printf("PROGRAMA FINALIZADO.");
          return 0;
        }else{
          printf("\n\nOPCAO INVALIDA \nTente novamente.\n\n");
          printf("Pressione qualquer tecla para continuar...");
          getch();
          system("cls");
        }
    }
}

