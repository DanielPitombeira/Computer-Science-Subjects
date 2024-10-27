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
    node *ptr;
    int i, valor;

    node *head_node = create_node(0);
    head = head_node;
    ptr = head;

    for(i = 0; i < n; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &valor);
        node *no = create_node(valor);

        ptr->next = no;
        ptr = no;
    }
    
    return head;
}

node *intercala(node *head1, node *head2){
    node *ptr1, *ptr2, *ptr3;
    node *head = create_node(0);
    ptr1 = head1->next;
    ptr2 = head2->next;
    ptr3 = head;
    int i = 0;

    while(ptr2 != NULL){
        if(i % 2 == 0){
            ptr3->next = create_node(ptr1->data);
            ptr1 = ptr1->next;
        }else{
            ptr3->next = create_node(ptr2->data);
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
        i++;
    }

    return head;
}

void print(node *head){
    node *ptr;
    ptr = head->next;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}