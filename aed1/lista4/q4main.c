#include <stdio.h>
#include <stdlib.h>
#include "q4.h"

int main(){
    node lista;
    lista.lenght = 0;
    int n, x, par;

    printf("quantidade de elementos: ");
    scanf("%d", &n);

    while(n--){
        printf("valor do elemento: ");
        scanf("%d", &x);
        insere(&lista, x);
    }

    par = numero_par(&lista);

    printf("tem %d pares\n", par);

    return 0;
}