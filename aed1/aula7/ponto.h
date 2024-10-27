#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    float x;
    float y;
    float z;
};
typedef struct ponto Ponto;

Ponto* criar_ponto(float novo_x, float novo_y, float novo_z);

void liberar_ponto(Ponto* p);

void acessar_ponto(Ponto* p, float* x, float* y, float* z);

void atribuir_ponto(Ponto* p, float novo_x, float novo_y, float novo_z);

float calcular_distancia(Ponto* , Ponto* );