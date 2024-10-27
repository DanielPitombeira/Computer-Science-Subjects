#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

node *head1;
node *head2;

int main(){  
    int n;

    printf("tamanho da lista: ");
    scanf("%d", &n);

    head1 = create_list(head1, n);

    head2 = create_node(0);
    head2 = lista_ordenada(head1, head2);
    print(head2);

    return 0;
}