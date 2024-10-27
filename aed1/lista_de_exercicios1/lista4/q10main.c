#include <stdio.h>
#include <stdlib.h>
#include "q10.h"

node *head = NULL;

int main(){
    int n, s;

    printf("tamanho da lista: ");
    scanf("%d", &n);

    head = create_list(head, n);
    s = soma(head); 

    printf("%d\n", s);

    return 0;
}