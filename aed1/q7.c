#include <stdio.h>

typedef struct{
    char nome[50];
    int matricula;
    char curso[50];
}Aluno;

int main(){
    Aluno A[2];
    for(int i = 0; i < 2; i++){
        printf("Qual seu nome: ");
        scanf("%[^\n]", A[i].nome);
        printf("Qual sua matricula: ");
        scanf("%d", &A[i].matricula);
        printf("Qual seu curso: ");
        scanf("%*c%[^\n]%*c", A[i].curso);
    }
    for(int i = 0; i < 2; i++){
        printf("Aluno %d\n", i+1);
        printf("Nome: %s\n", A[i].nome);
        printf("Matricula: %d\n", A[i].matricula);
        printf("Curso: %s\n\n", A[i].curso);
    }

    return 0;
}