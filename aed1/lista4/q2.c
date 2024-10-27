#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

void insere(node *list, int valor){
    if(list->lenght >= MAX){
        printf("lista cheia!!!");
        return;
    }

    list->data[list->lenght++] = valor;
}

void remove_elements(node *list, int n){
    int i, j;
    
    if(list->lenght == 0 || list->lenght < n){
        printf("operacao nao foi posivel\n");
        return;
    }

    for(i = n-1; i >= 0; i--){
        for(j = i; j < list->lenght; j++){
            list->data[j] = list->data[j+1];
        }
        list->lenght--; 
    }
    printf("operacao foi possivel\n");
}

void print(node *list){
    int i;

    for(i = 0; i < list->lenght; i++){
        printf("%d\n", list->data[i]);
    }
}