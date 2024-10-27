#include <stdio.h>

int main(){
    int x1, x2, soma;
    scanf("%d%d", &x1, &x2);

    soma = x1 + x2;
    printf("soma: %d\n", soma);
    if(x1 > x2) printf("x1 é maior\n");
    else if(x2 > x1) printf("x2 é maior\n");

    return 0;
}