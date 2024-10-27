#include "retangulo.h"


Ret *cria_retangulo(int altura, int largura){
    Ret *novo_retangulo = (Ret*)(malloc(sizeof(Ret)));
    if(novo_retangulo != NULL){
        novo_retangulo->largura = largura;
        novo_retangulo->altura = altura;
    }
    return novo_retangulo;
}

void retorna_ret(Ret *retangulo, int *altura, int *largura){
    *altura = retangulo->altura;
    *largura = retangulo->largura;
}

int perimetro(Ret *R){
    return (2*(R->altura) + 2*(R->largura));
}

int area(Ret *R){
    return ((R->altura) * (R->largura));
}   

void libera(Ret *R){
    if (R != NULL) {
        free(R);
    }
}