#include <stdio.h>
#include "q5.h"

int main(){
    int op, quantidade = 0, identificador, aux = 0;
    char nome[20];

    while(1){
        printf("operacao: \n");
        printf("1- quantidade de avioes aguardando\n");
        printf("2- decolar primeiro aviao\n");
        printf("3- adicionar aviao a fila de espera\n");
        printf("4- listar todos os avioes na fila de espera\n");
        printf("5- primeiro aviao\n");
        printf("6- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("quantidade: %d\n", quantidade);
                break;
            case 2: 
                if(decolar() == 1)
                    quantidade--;
                break;
            case 3:
                printf("nome do aviao: ");
                scanf("%*c%s", nome);
                printf("identificador: ");
                scanf("%d", &identificador);
                adicionar(nome, identificador);
                quantidade++;
                break;
            case 4:
                print();
                break;
            case 5:
                top();
                break;
            case 6:
                aux = 1;
                break;
            default: 
                printf("operacao invalida\n");
                break;
        }

        if(aux == 1)
            break;
    }

    return 0;
}
