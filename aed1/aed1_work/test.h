#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct music{
    char nome[30];
    struct music* prox;
};

struct user{
    char nome[30];
    struct user* prox;
    struct music* desce;
};

typedef struct user user;
typedef struct music music;

user* cria_usuario(char nome[]);
music* cria_musica(char nome_musica[]);
void adiciona_usuario(char nome[]);
void adiciona_musica(char nome[], char nome_musica[]);
void excluir(char nome[], char nome_musica[]);
void print();
