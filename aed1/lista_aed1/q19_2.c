#include "q19_2.h"

void initialize(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Pilha cheia\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

void reverse(Stack* stack) {
    int tempStack[MAX_SIZE];
    int i = 0;

    while (!isEmpty(stack)) {
        tempStack[i++] = pop(stack);
    }

    for (int j = 0; j < i; j++) {
        push(stack, tempStack[j]);
    }
}

void print(Stack* stack) {
    Stack tempStack;
    initialize(&tempStack);

    while (!isEmpty(stack)) {
        int item = pop(stack);
        push(&tempStack, item);
        printf("%d\n", item);
    }

    while (!isEmpty(&tempStack)) {
        int item = pop(&tempStack);
        push(stack, item);
    }
}

