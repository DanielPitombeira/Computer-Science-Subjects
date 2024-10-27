#include <stdio.h>
#define MAX 100000

struct array{
    int vetor[MAX];
    int n;
};

typedef struct array array;
array T;

void inicializa(){
    T.n = 0;
}

void push(int data){
    if(T.n == MAX){
        printf("vetor cheio\n");
    }else{
        T.n++;
        T.vetor[T.n] = data;
    }
}

int search(int data){
    int i = T.n;

    while(i--){
        if(T.vetor[i] == data)
            return i;
    }

    return i;
}

int main(){
    int op, data;

    while(1){
        printf("operacoes: \n");
        printf("1- inserir\n");
        printf("2- pesquisar\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor: \n");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf("valor para pesquisar: \n");
        }
    }
}