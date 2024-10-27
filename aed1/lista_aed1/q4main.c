#include <stdio.h>
#include "q4.h"

int main(){
    int op, aux = 0, registro;

    while(1){
        printf("operacoes: \n");
        printf("1- adicionar processo\n");
        printf("2- retirar processo com maior tempo de espera\n");
        printf("3- imprimir lista de processos\n");
        printf("4- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor do registro: \n");
                scanf("%d", &registro);
                queue(registro, 0);
                break;
            case 2:
                top();
                break;
            case 3:
                print();
                break;
            case 4:
                aux = 1;
                break;
            default: 
                printf("operacao invalida\n");
                break;
        }

        if(aux == 1) 
            break;

        time();
    }

    return 0;
}