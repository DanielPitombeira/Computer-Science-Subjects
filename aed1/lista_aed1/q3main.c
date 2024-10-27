#include <stdio.h>
#include "q3.h"

int main(){
    int op, prioridade, aux = 0, p;

    while(1){
        printf("Digite a operacao: \n");
        printf("1- adicionar elemento\n");
        printf("2- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor inteiro: ");
                scanf("%d", &prioridade);
                enfileirar(prioridade, &front1, &rear1);
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

    printf("informe o valor p: ");
    scanf("%d", &p);

    divida_filas(p);

    printf("fila 2\n");
    imprimir(&front2, &rear2);

    printf("fila 3\n");
    imprimir(&front3, &rear3);

    return 0;
}
