#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

node *head1;
node *head2;

int main(){  
    int n;

    printf("tamanho da lista: ");
    scanf("%d", &n);

    head1 = create_list(head1, n);

    printf("tamanho da lista: ");
    scanf("%d", &n);

    head2 = create_list(head2, n);

    head1 = ordena(head1, head2);

    return 0;
}