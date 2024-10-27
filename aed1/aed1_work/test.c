#include "test.h"

user* cabeca = NULL;

user* cria_usuario(char nome[]){
    user* usuario;

    usuario = (user*)malloc(sizeof(user));
    strcpy(usuario->nome, nome);
    usuario->prox = NULL;
    usuario->desce = NULL;

    return usuario;
}

music* cria_musica(char nome_musica[]){
    music* musica;

    musica = (music*)malloc(sizeof(music));
    strcpy(musica->nome, nome_musica);
    musica->prox = NULL;

    return musica;
}

void adiciona_usuario(char nome[]){
    user* usuario;

    usuario = cria_usuario(nome);

    usuario->prox = cabeca;
    cabeca = usuario;
}

void adiciona_musica(char nome[], char nome_musica[]){
    user* temp = cabeca;

    while(temp != NULL){
        if(strcmp(temp->nome, nome) == 0){
            break;
        }

        temp = temp->prox;
    }

    if(temp == NULL)
        printf("Usuario nao encontrado\n");
    else{
        music* musica;

        musica = cria_musica(nome_musica);
        if(temp->desce == NULL){

            temp->desce = musica;
            return;
        }

        musica->prox = temp->desce;
        temp->desce = musica;
    }
}

void print(){
    user* temp1 = cabeca;

    while(temp1 != NULL){
        printf("\n");
        music* temp2 = temp1->desce;

        printf("Musicas de %s: \n\n", temp1->nome);
        while(temp2 != NULL){
            printf("%s\n", temp2->nome);

            temp2 = temp2->prox; 
        }

        temp1 = temp1->prox;
    }
}

void excluir(char nome[], char nome_musica[]){
    user* temp1;
}
