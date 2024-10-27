#include <stdio.h>
#include <stdlib.h>

struct node{
    char letter;
    struct node* next;
};

typedef struct node node;

node* create_node(char ch);
void push(char string[]);
void pop();
void palindromo();
