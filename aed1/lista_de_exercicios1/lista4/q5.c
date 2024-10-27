#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

void insere(node *list, int valor){
    if(list->lenght >= MAX){
        printf("lista cheia!!!");
        return;
    }

    list->data[list->lenght++] = valor;
}

int media(node *list){
    int i, soma = 0, media;

    for(i = 0; i < list->lenght; i++){
        soma += list->data[i];
    }
    media = (soma)/(list->lenght);
    
    return media;
}