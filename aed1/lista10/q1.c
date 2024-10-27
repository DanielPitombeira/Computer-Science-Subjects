#include <stdio.h>
#include "q1.h"

int main(){
    int op, codigo, aux = 0;
    float salario;

    while(1){
        printf("Escolha a operacao a ser realizada: \n");
        printf("1- verifica fila vazia\n2- enfileirar\n3- desinfileirar\n4- imprimir fila\n");
        printf("5- menor valor, maior valor, media\n6- quantos salarios e valor total a ser pago\n");
        printf("7- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                fila_vazia();
                break;
            case 2:
                printf("Digite o codigo do funcionario: ");
                scanf("%d", &codigo);
                printf("Digite o salario do funcionario: ");
                scanf("%f", &salario);
                enfileirar(codigo, salario);
                break;
            case 3:
                desenfileirar();
                break;
            case 4:
                imprimir();
                break;
            case 5:
                function_a();
                break;
            case 6:
                function_b();
                break;
            case 7:
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