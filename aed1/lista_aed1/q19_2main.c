#include <stdio.h>
#include "q19_2.h"

int main() {
    Stack stack;
    initialize(&stack);

    int op, data, aux = 0;

    while(1) {
        printf("operacoes: \n");
        printf("1- adicionar\n");
        printf("2- sair\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("valor do elemento: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                aux = 1;
                break;
            default:
                printf("operacao invalida\n");
                break;
        }
        if(aux == 1)
            break;
    } 

    print(&stack);

    return 0;
}

