#include <stdio.h>
#include "q2.h"

int main(){
    int op, data, tam = 0;

    while(1){
        printf("Escolha a operacao:\n"); 
        printf("1- pilha vazia\n2- empilhar\n3- desempilhar\n4- tamanho\n5- imprimir\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                pilha_vazia();
                break;
            case 2:
                printf("elemento a adicionar: ");
                scanf("%d", &data);
                empilhar(data, &tam);
                break;
            case 3:
                desempilhar(&tam);
                break;
            case 4:
                printf("tamanho: %d\n", tam);
                break;
            case 5:
                imprimir();
                break;
            default:
                printf("operacao invalida\n");
                break;
        }
    }

    return 0;
}