//implementacao dinamica
#include <stdio.h>
#include "q15.h"

int main(){
    int op, aux = 0, data;

    while(1){
        printf("operacoes: \n");
        printf("1- adiciona\n");
        printf("2- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor do elemento: \n");
                scanf("%d", &data);
                push(data);
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

    inverta();
    print();

    return 0;
}

