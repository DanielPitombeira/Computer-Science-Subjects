#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int length;
} node;

void insereValor(node *list, int valor);
node concatenaListas(const node *list1, const node *list2);
void print(node *result);