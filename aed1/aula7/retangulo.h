#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int largura;
    int altura;
}Ret;

Ret *cria_retangulo(int, int);

void retorna_ret(Ret *, int *, int *);

int perimetro(Ret *);

int area(Ret *);

void libera(Ret *);