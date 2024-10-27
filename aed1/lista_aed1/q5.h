#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int identificador;
    char nome[20];

    struct node* next;
};

typedef struct node node;

int decolar();
void adicionar(char nome[], int identificador);
void print();
void top();
