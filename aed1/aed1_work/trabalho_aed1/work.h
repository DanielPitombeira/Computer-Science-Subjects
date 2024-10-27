#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct musica{
    char nome_musica[30];
    char nome_autor[30];
    struct musica* prox; //apontador para a pŕoxima célula(próxima música)
};

struct usuario{
    char nome[30];
    char email[30];
    char senha[30];
    struct usuario* prox; //apontador para a pŕoxima célula(próximo usuário)
    struct musica* cabeca; //apontador para a cabeça da lista de músicas
};

typedef struct musica musica;
typedef struct usuario usuario;

void print(); 
void print_musica(usuario* user);

usuario* cria_usuario(char nome[], char email[], char senha[]);
void adiciona_usuario(char nome[], char email[], char senha[]);

musica* cria_musica(char nome_autor[], char nome_musica[]);
void adiciona_musica(usuario* user, char nome_autor[], char nome_musica[]);

bool search(char email[], char senha[], usuario** user); 

int particao(musica* v, int inicio, int fim);
void QuickSort(musica* v, int inicio, int fim);
void Merge(musica *v1, int esquerda, musica *v2, int direita, musica *v, int n);
void MergeSort(musica *v, int n);
void BubbleSort(musica* v, int n);
void cria_pilha(usuario* user);
void push(char nome_autor[], char nome_musica[]);
void top();
void pop();

void excluir_usuario(char email[], char senha[]);
void excluir_musica(usuario* user, char nome_autor[], char nome_musica[]);
void excluir_tudo();

bool isEmpty(usuario* user ,int n);
