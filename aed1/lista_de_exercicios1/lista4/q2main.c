#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

int main(){
    node lista;
    lista.lenght = 0;
    int n, x;

    printf("NUmero de elementos a inserir: ");
    scanf("%d", &n);

    while(n--){
        printf("Valor do elemento: ");
        scanf("%d", &x);
        insere(&lista, x);
    }
    printf("Quantidade dos n primeiros elementos a remover: ");
    scanf("%d", &n);
    remove_elements(&lista, n);

    print(&lista);

    return 0;
}