#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

void insereValor(node *list, int valor) {
    if (list->length >= MAX) {
        printf("Lista cheia!\n");
        return;
    }

    list->data[list->length++] = valor;
}

node concatenaListas(const node *list1, const node *list2) {
    node result;
    result.length = 0;

    for (int i = 0; i < list1->length; i++) {
        result.data[result.length++] = list1->data[i];
    }

    for (int i = 0; i < list2->length; i++) {
        result.data[result.length++] = list2->data[i];
    }

    return result;
}   

void print(node *result){
    int i;

    for(i = 0; i < result->length; i++){
        printf("%d\n", result->data[i]);
    }
}