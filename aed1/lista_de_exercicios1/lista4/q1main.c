#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

int main(){
    node lista1;
    lista1.length = 0;
    int n1, n2, x;
    node lista2;
    lista2.length = 0;
    node result;

    printf("NUmero de elementos da lista1: ");
    scanf("%d", &n1);
    while(n1--){
        printf("valor do elemento: ");
        scanf("%d", &x);
        insereValor(&lista1, x);
    }
    printf("NUmero de elementos da lista2: ");
    scanf("%d", &n2);
    while(n2--){
        printf("valor do elemento: ");
        scanf("%d", &x);
        insereValor(&lista2, x);
    }
    result = concatenaListas(&lista1, &lista2);
    print(&result);

    return 0;
}