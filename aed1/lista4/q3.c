#include <stdio.h>
#include <stdlib.h>
#include "q3.h"

void insere(node *list, int valor){
    if(list->lenght >= MAX){
        printf("lista cheia!!!");
        return;
    }

    list->data[list->lenght++] = valor;
}

void maior_elemento(node *list, int *maior, int *pos){
    int i;  

    if(list->lenght == 0){
        printf("operacao impossivel\n");
    }else{
        for(i = 0; i < list->lenght; i++){
            if(i == 0) {
                *maior = list->data[i];
                *pos = i+1;
            }

            if(list->data[i] > *maior){
                *maior = list->data[i];
                *pos = i+1;
            }
        }
    }
}

void print(node *list){
    int i;

    for(i = 0; i < list->lenght; i++){
        printf("%d\n", list->data[i]);
    }
}