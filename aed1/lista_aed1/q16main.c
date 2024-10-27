#include <stdio.h>
#include "q16.h"

int main(){
    int op, data, aux = 0;

    while(1){
        printf("operacoes: \n");
        printf("1- adiciona\n");
        printf("2- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor do elemento: \n");
                scanf("%d", &data);
                push(data, &front1, &rear1);
                break;
            case 2:
                aux = 1;
                break;
            default:
                printf("operacao invalido\n");
                break;
        }

        if(aux == 1)
            break;
    }

    apaga();
    print();

    return 0;
}
