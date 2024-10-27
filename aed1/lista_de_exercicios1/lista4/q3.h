#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

struct node{
    int data[MAX];
    int lenght;
};

typedef struct node node;

void insere(node *list, int valor);
void maior_elemento(node *list, int *maior, int *pos);
void print(node *list);