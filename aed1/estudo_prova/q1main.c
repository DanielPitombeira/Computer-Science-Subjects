#include "q1.h"

int main(){
    int op, data, aux1, aux2 = 0;

    while(1){
        printf("operacoes: \n");
        printf("1- verificar lista\n");
        printf("2- inserir no inicio\n");
        printf("3- inserir no fim\n");
        printf("4- remover no inicio\n");
        printf("5- remover no fim\n");
        printf("6- buscar elemento\n");
        printf("7- quantidade de elementos\n");
        printf("8- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1: 
                aux1 = isEmpty();
                if(aux1 == 1){
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
                printf("valor do elemento: \n");
                scanf("%d", &data);
                search(data);
                break;
            case 7:
                number();
                break;
            case 8:
                aux2 = 1;
                break;
            default:
                printf("valor invalido\n");
                break;
        }

        printf("\n");
        print();

        if(aux2 == 1)
            break;
    }

    return 0;
}