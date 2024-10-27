#include "q3.h"

int main(){
    int op, data, aux = 0;

    while(1){
        printf("1- empilha\n");
        printf("2- desempilha\n");
        printf("3- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor: \n");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                aux = 1;
                break;
        }

        if(aux == 1)
            break;
        
        print();
    }

    return 0;
}