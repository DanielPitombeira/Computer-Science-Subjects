#include <stdio.h>

int main(){
    int op;
    double x1, x2, soma;

    printf("Digite a operacao desejada: \n");
    printf("1 - Adicao\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n"); 
    scanf("%d", &op);
    switch(op){
        case 1: 
            scanf("%lf %lf", &x1, &x2);
            printf("soma: %.2lf\n", x1+x2);
            break;
        case 2:
            scanf("%lf %lf", &x1, &x2);
            printf("subtracao: %.2lf\n", x1-x2);
            break;
        case 3:
            scanf("%lf %lf", &x1, &x2);
            printf("multiplicacao: %.2lf\n", x1*x2);
            break;
        case 4:
            scanf("%lf %lf", &x1, &x2);
            printf("divisao: %.2lf\n", x1/x2);
            break;
        default:
            printf("Operacao invalida!\n");
    }

    return 0;
}