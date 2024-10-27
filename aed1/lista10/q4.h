#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef node node;

void lista_vazia();
void inserir_inicio(int num);
void inserir_final(int num);