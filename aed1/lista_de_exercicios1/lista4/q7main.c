#include <stdio.h>
#include <stdlib.h>
#include "q7.h"

node *head1 = NULL;
node *head2 = NULL;

int main(){
    int n;

    printf("quantos elementos tem a lista 1: ");
    scanf("%d", &n);
    head1 = create_list(head1, n);

    printf("quantos elementos tem a lista 2: ");
    scanf("%d", &n);
    head2 = create_list(head2, n);

    head1 = concatena(head1, head2);
    print(head1);

    return 0;
}