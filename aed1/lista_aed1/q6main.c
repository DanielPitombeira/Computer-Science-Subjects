#include <stdio.h>
#include "q6.h"

int main(){
    
    for(int i = 0; i < 2; i++){
        int op, data, aux = 0;

        while(1){
            printf("operacao: \n");
            printf("1- adicionar elemento\n");
            printf("2- sair\n");

            scanf("%d", &op);

            switch(op){
                case 1:
                    printf("valor: \n");
                    scanf("%d", &data);
                    queue(data, &front1, &rear1);
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
    }

    new_queue();
    print();

    return 0;
}
