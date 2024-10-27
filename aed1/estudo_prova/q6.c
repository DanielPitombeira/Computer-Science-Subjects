#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* stack1 = NULL;
node* stack2 = NULL;

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;
}

void push(node** stack, int data){
    node* no;

    no = create_node(data);

    if(*stack == NULL){
        *stack = no;
        return;
    }

    no->next = *stack;
    *stack = no;
}

void pop(node** stack){
    if(*stack == NULL){
        return;
    }

    node* temp = *stack;

    *stack = (*stack)->next;
    free(temp);
}

int count(node** stack){
    int sum = 0;
    int *v = NULL, i = 0, count = 0;

    while(*stack != NULL){
        sum++;

        count++;
        int *temp = realloc(v, count * sizeof(int));

        v = temp;
        v[i] = (*stack)->data;
        i++;

        pop(stack);
    }

    for(int j = count - 1; j >= 0; j--)
        push(stack, v[j]);

    return sum;
}

void print(node** stack){
    node* temp = *stack;

    while(temp != NULL){
        printf("%d ", temp->data);

        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int op, data, aux = 0, num1, num2;

    while(1){
        printf("operacoes: \n");
        printf("1- push pilha1\n");
        printf("2- push pilha2\n");
        printf("3- sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("valor: ");
                scanf("%d", &data);
                push(&stack1, data);
                break;
            case 2:
                printf("valor: ");
                scanf("%d", &data);
                push(&stack2, data);
                break;
            case 3:
                aux = 1;
                break;
            default:
                printf("valor invalido\n");
        }

        if(aux == 1)
            break;
    }

    num1 = count(&stack1);
    num2 = count(&stack2);

    if(num1 > num2)
        printf("a primeira e maior\n");
    else if(num1 < num2)
        printf("a segunda e maior\n");
    else
        printf("sao iguais\n");

    printf("pilha 1:\n");
    print(&stack1);

    printf("pilha 2: \n");
    print(&stack2);

    return 0;
}