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

node *intercala(node *head1, node *head2){
    node *ptr1, *ptr2, *ptr3, *current;
    node *head = NULL;
    ptr1 = head1;
    ptr2 = head2;
    int i = 0;

    while(ptr1 != NULL && ptr2 != NULL){
        if(i % 2 == 0){
            ptr3 = create_node(ptr1->data);
            if(head == NULL){
                head = ptr3;
                current = ptr3;
            }else{
                current->next = ptr3;
                current = current->next;
            }
            ptr1 = ptr1->next;
        }else{
            ptr3 = create_node(ptr2->data);
            if(head == NULL){
                head = ptr3;
                current = ptr3;
            }else{
                current->next = ptr3;
                current = current->next;
            }
            ptr2 = ptr2->next;
        }
        i++;
    }

    return head;
}

void print(node *head){
    node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}