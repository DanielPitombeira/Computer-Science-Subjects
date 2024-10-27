#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

int main(){
    node lista;
    lista.lenght = 0;
    int n, x, maior, pos;

    printf("quantidade de elementos: ");
    scanf("%d", &n);

    while(n--){
        printf("Inserir valor: ");
        scanf("%d", &x);
        insere(&lista, x);
    }
    maior_elemento(&lista, &maior, &pos);
    printf("Maior elemento: %d\nPosicao: %d\n", maior, pos);

    return 0;
}