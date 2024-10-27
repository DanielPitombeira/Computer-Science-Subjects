#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *create_node(int valor){
    node *no;

    no = malloc(sizeof(node));
    no->data = valor;
    no->next = NULL;

    return no;
}

node *create_list(node *head, int n){
    int i, valor;

    for(i = 0; i < n; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &valor);
        node *no = create_node(valor);

        no->next = head;
        head = no;
    }

    return head;
}

node *elementos_repetidos(node *head){
    node *ptr1, *ptr2, *ptr3;
    ptr1 = head;

    while(ptr1 != NULL){
        ptr3 = ptr1;
        ptr2 = ptr1->next;
        while(ptr2 != NULL){
            if(ptr2->data == ptr1->data){
                ptr3->next = ptr2->next;
                free(ptr2);
                ptr2 = ptr3->next;
            }else{
                ptr3 = ptr2;
                ptr2 = ptr2->next; 
            }
        }
        ptr1 = ptr1->next;
    }

    return head;
}

void print(node *head){
    node *ptr = head;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}