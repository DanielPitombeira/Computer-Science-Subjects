#include "test.h"

int main(){
    int op, aux = 0;
    char nome[30], nome_musica[30];

    while(1){
        printf("operacoes: \n");
        printf("1- adicionar usuario\n");
        printf("2- adicionar musica na playlist de um usuario\n");
        printf("3- imprimir matriz\n");
        printf("4- excluir musica\n");
        printf("5- sair\n");
        scanf("%d", &op);

        printf("\n");
        switch(op){
            case 1:
                printf("Nome do usuario: \n");
                scanf("%*c%[^\n]", nome);
                adiciona_usuario(nome);
                break;
            case 2:
                printf("Qual usuario adicionara a musica: \n");
                scanf("%*c%[^\n]", nome);
                printf("Nome da musica: \n");
                scanf("%*c%[^\n]", nome_musica);
                adiciona_musica(nome, nome_musica);
                break;
            case 3:
                print();
                break;
            case 4:
                printf("Qual usuario adicionara a musica: \n");
                scanf("%*c%[^\n]", nome);
                printf("Nome da musica para excluir: \n");
                scanf("%*c%[^\n]", nome_musica);
                excluir(nome, nome_musica);
                break;
            case 5:
                aux = 1;
                break;
            default: 
                printf("Valor invalido\n");
                break;
        }
        if(aux == 1)
            break;
        printf("\n");
    }

    return 0;
}
