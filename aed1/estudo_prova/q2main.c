#include "q2.h"

int main(){
    int op, data, aux = 0;

    while(1){
        printf("operacoes: \n");
        printf("1- verifica lista\n");
        printf("2- inserir elemento no começo\n");
        printf("3- inserir elemento no fim\n");
        printf("4- remover elemento no comeco\n");
        printf("5- remover elemento no fim\n");
        printf("6- imprimir lista do começo para o fim\n");
        printf("7- imprimir lista do fim para o começo\n");
        printf("8- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                if(isEmpty()){
                    printf("Lista vazia\n");
                }else{
                    printf("Lista nao vazia\n");
                }
                break;
            case 2:
                printf("valor do elemento: \n");
                scanf("%d", &data);
                pushAtBegg(data);
                break;
            case 3:
                printf("valor do elemento: \n");
                scanf("%d", &data);
                pushAtEnd(data);
                break;
            case 4:
                popAtBegg();
                break;
            case 5:
                popAtEnd();
                break;
            case 6:
                printAtBegg();
                break;
            case 7:
                printAtEnd();
                break;
            case 8:
                aux = 1;
                break;
            default:
                printf("operacao invalida\n");
                break;
        }

        if(aux == 1){
            break;
        }
    }

    return 0;
}