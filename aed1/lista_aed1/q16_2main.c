#include "q16_2.h"

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
                push1(data);
                break;
            case 2:
                aux = 1;
                break;
            default:
                printf("valor invalido\n");
                break;
        }

        if(aux == 1)
            break;
    }   

    apaga_negativos();
    print();

    return 0;
}
