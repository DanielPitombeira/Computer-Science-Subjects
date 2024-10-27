#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

int main(){
    node lista;
    lista.lenght = 0;
    int n, x, m;

    printf("quantidade de valores: ");
    scanf("%d", &n);

    while(n--){
        printf("valor do elemento: ");
        scanf("%d", &x);
        insere(&lista, x);
    }
    m = media(&lista);
    printf("media: %d\n", m);

    return 0;
}