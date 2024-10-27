#include <stdio.h>
#include "q11.h"

int main(){
    int op, aux = 0, data;

    while(1){
        printf("operacoes: \n");
        printf("0- sair\n");
        printf("1- adicionar\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                aux = 1;
                break;
            case 1: 
                printf("valor do elemento: \n");
                scanf("%d", &data);

                if(data % 2 == 0)
                    push_fila(data, &front_par, &rear_par);
                else
                    push_fila(data, &front_impar, &rear_impar);
                break;
            default:
                printf("valor invalido\n");
                break;
        }

        if(aux == 1)
            break;
    }

    funcao();
    print();

    return 0;
}

