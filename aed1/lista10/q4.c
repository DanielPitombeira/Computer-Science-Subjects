#include <stdio.h>
#include "q4.h"

int main(){
    int op, num;

    while(1){
        printf("Escolha a operacao: \n");
        printf("1- verifica lista vazia\n");
        printf("2- inserir elemento no inicio\n");
        printf("3- inserir elemento no final\n");
        printf("4- remover elemento no inicio\n");
        printf("5- remover elemento no final\n");
        printf("6- sair\n");

        scanf("%d", &op);

        switch(op){
            case 1:
                lista_vazia();
                break;
            case 2:
                printf("Numero a ser inserido: ");
                scanf("%d", &num);
                inserir_inicio(num);
                break;
            case 3:   
                printf("Numero a ser inserido: ");
                scanf("%d", &num);
                inserir_final(num);
                break; 
        }
    }

    return 0;
}