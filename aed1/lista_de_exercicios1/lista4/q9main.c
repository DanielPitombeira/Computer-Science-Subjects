#include <stdio.h>
#include <stdlib.h>
#include "q9.h"

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;

int main(){
    int n;

    printf("tamanho da lista 1: ");
    scanf("%d", &n);
    head1 = create_list(head1, n);

    printf("tamanho da lista 2: ");
    scanf("%d", &n);
    head2 = create_list(head2, n);

    head3 = intercala(head1, head2);
    print(head3);

    return 0;
}