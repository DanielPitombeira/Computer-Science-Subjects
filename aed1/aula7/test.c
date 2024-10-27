#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    node *head = NULL, *ptr;
    int nos, data, position;

    printf("quantos nos: ");
    scanf("%d", &nos);
    head = addend(head, nos);

    printf("Numero de elementos adicionados no inicio: ");
    scanf("%d", &nos);
    while(nos--){
        printf("valor do dado: ");
        scanf("%d", &data);
        head = add_at_the_beginning(head, data);
    }
    
    printf("NUmero de insercao em qualquer posicao: ");
    scanf("%d", &nos);
    while(nos--){
        printf("valor do dado: ");
        scanf("%d", &data);
        printf("posicao de insercao: ");
        scanf("%d", &position);
        head = add_pos(head, data, position);
    }

    printf("Numero de elementos a ser apagados no inicio: ");
    scanf("%d", &nos);
    while(nos--){
        head = apaga_ini(head);
    }

    printf("Numero de elementos a ser apagados no fim: ");
    scanf("%d", &nos);
    while(nos--){
        head = apaga_fim(head);
    }

    printf("Numero de elementos a ser apagados em qualquer posicao: ");
    scanf("%d", &nos);
    while(nos--){
        printf("Qual a posicao: ");
        scanf("%d", &position);
        head = del_pos(head, position);
    }

    head = reverse(head);

    count_node(head);
    print_dado(head);

    return 0;
}