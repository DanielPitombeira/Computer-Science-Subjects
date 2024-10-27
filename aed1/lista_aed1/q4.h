#include <stdio.h>
#include <stdlib.h>

struct node{
    int registro;
    int tempo;

    struct node* next;
};

typedef struct node node;

void queue(int registro, int tempo);
void top();
void unqueue();
void print();
void time();
