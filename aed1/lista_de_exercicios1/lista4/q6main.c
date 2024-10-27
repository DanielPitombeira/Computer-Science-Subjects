#include <stdio.h>
#include <stdlib.h>
#include "q6.h"

node *head = NULL;

int main(){
    int n;

    printf("numero de elementos de um vetor: "); 
    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++){
        printf("Digite o valor do elemento: ");
        scanf("%d", &v[i]);
    }
    head = cria_lista(head, v, n);

    print(head);

    return 0;
}