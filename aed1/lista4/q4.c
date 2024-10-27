#include <stdio.h>
#include <stdlib.h>
#include "q4.h"

void insere(node *list, int valor){
    if(list->lenght >= MAX){
        printf("lista cheia!!!");
        return;
    }

    list->data[list->lenght++] = valor;
}

int numero_par(node *list){
    int i, n_par = 0;

    for(i = 0; i < list->lenght; i++){
        if(list->data[i] % 2 == 0) n_par++;
    }

    return n_par;
}
