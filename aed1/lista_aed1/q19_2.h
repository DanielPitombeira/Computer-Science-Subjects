#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
void reverse(Stack* stack);
void print(Stack* stack);

