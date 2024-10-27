#include <stdio.h>
#define MAX 10

int stack1[MAX];
int ind1 = -1;

int stack2[MAX];
int ind2 = -1;

void push(int *stack, int *ind, int data){
    (*ind)++;
    stack[*ind] = data;
}

void pop(int *ind){
    if (*ind >= 0)
        (*ind)--;
}

int count(int *stack, int *ind){
    int n = (*ind) + 1;
    int i = 0, sum = 0, v[n];

    while ((*ind) != -1){
        v[i] = stack[*ind];
        i++;
        sum++;

        pop(&(*ind)); // ou pop(ind) - ind já armazena o endereço do ponteiro
    }

    for (int j = i - 1; j >= 0; j--)
        push(stack, &(*ind), v[j]);

    return sum;
}

void print(int *stack, int ind){
    for(int i = ind; i >= 0; i--){
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main(){
    int op, data, aux = 0, num1, num2;

    while (1){
        printf("Operacoes: \n");
        printf("1- push pilha1\n");
        printf("2- push pilha2\n");
        printf("3- sair\n");
        scanf("%d", &op);

        switch (op){
        case 1:
            printf("valor: ");
            scanf("%d", &data);
            push(stack1, &ind1, data);
            break;
        case 2:
            printf("valor: ");
            scanf("%d", &data);
            push(stack2, &ind2, data);
            break;
        case 3:
            aux = 1;
            break;
        default:
            printf("valor invalido\n");
        }
        if (aux == 1)
            break;
    }
    print(stack1, ind1);
    print(stack2, ind2);

    num1 = count(stack1, &ind1);
    num2 = count(stack2, &ind2);

    if (num1 > num2)
        printf("A pilha 1 tem mais elementos que a pilha 2.\n");
    else if (num1 < num2)
        printf("A pilha 2 tem mais elementos que a pilha 1.\n");
    else
        printf("As pilhas têm a mesma quantidade de elementos.\n");

    return 0;
}
