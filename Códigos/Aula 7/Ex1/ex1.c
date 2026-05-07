#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(){
    float nota[10],somador, media;
    int i;

    for(i = 0; i < 10; i++){
        system("cls");
        printf("Digite nota %d: ", (i+1));
        scanf("%f", &nota[i]);
        somador = somador + nota[i];
    }

    media = somador / 10;
    printf("media = %.2f\n", media);
    return 0;
}
