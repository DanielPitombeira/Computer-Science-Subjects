#include <stdio.h>
#include "retangulo.h"

int main(){
    int largura1, altura1, altura, largura;
    Ret *R;

    printf("Digite a largura do retangulo: ");
    scanf("%d", &largura1);
    printf("Digite a altura do retangulo: ");
    scanf("%d", &altura1);
    
    R = cria_retangulo(altura1, largura1);
    retorna_ret(R, &altura, &largura);
    printf("altura: %d\nlargura: %d\n", altura, largura);
    printf("perimetro: %d\n", perimetro(R));
    printf("area: %d\n", area(R));

    return 0;
}