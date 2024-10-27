#include <stdio.h>
#include "q20.h"

int main(){
    int op, data, aux = 0;

    while(1){
        printf("operacoes: \n");
        printf("1- adicionar\n");
        printf("2- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor do elemento: \n");
                scanf("%d", &data);
                push(data, &stack1);
                break;
            case 2:
                aux = 1;
                break;
            default:
                printf("valor invalido\n");
                break;
        }
        if(aux == 1){
            break;
        }
    }
    copia();
    print();

    return 0;
}
