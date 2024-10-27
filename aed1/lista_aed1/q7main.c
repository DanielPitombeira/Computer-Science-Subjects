#include <stdio.h>
#include "q7.h"

int main(){
    int op, data, aux = 0;

    while(1){
        printf("Digite a operacao: \n");
        printf("1- adicionar elemento\n");
        printf("2- valor no topo\n");
        printf("3- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                top();
                break;
            case 3:
                aux = 1;
                break;
            default:
                printf("valor invalido\n");
                break;
        }

        if(aux == 1) 
            break;
    }

    return 0;
}
