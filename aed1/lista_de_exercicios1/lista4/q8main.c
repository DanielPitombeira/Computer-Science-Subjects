#include <stdio.h>
#include <stdlib.h>
#include "q8.h"

node *head = NULL;

int main(){
    int n;

    printf("quantidade de elementos da lista: ");
    scanf("%d", &n);

    head = create_list(head, n);
    head = elementos_repetidos(head);
    print(head);

    return 0;
}