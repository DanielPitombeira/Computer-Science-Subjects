#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

node *create_node(int data){
    node *no;

    no = malloc(sizeof(node));
    no->dado = data;
    no->link = NULL;

    return no;
}

node *addend(node *head, int nos){
    node *new_data, *ptr;
    int i, data;

    for(i = 0; i < nos; i++){
        printf("valor do no: ");
        scanf("%d", &data);
        new_data = create_node(data);

        if(head == NULL){
            head = new_data;
            ptr = new_data;
        }else{
            ptr->link = new_data;
            ptr = ptr->link;
        }
    } 

    return head;
}

node *add_at_the_beginning(node *head, int data){
    node *new_data;

    new_data = malloc(sizeof(node));
    new_data->dado = data;
    new_data->link = NULL;

    new_data->link = head;
    head = new_data;

    return head;
}

node *add_pos(node *head, int data, int position){
    node *ptr, *new_data;
    ptr = head;

    new_data = malloc(sizeof(node));
    new_data->dado = data;
    new_data->link = NULL;

    if(position == 1){
        new_data->link = head;
        head = new_data;
        return head;
    }
    for(int i = 0; i < position-2; i++){
        ptr = ptr->link;
    }
    new_data->link = ptr->link;
    ptr->link = new_data;

    return head;
}

node *apaga_ini(node *head){
    node *temp = head;
    if(head == NULL){
        printf("Lista vazia\n");
    }else{
        head = head->link;
        free(temp);
        temp = NULL;
    }
    
    return head;
}

node *apaga_fim(node *head){
    if(head == NULL){
        printf("Lista vazia\n");
    }else if(head->link == NULL){
        free(head->link);
        head = NULL;
    }else{
        node *temp = head->link;
        node *temp2 = head;

        while(temp->link != NULL){
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }

    return head;
}

node *del_pos(node *head, int position){
    node *ptr1 = head;
    node *ptr2 = head;

    if(head == NULL){
        printf("Lista vazia\n");
    }else if(position == 1){
        head = ptr2->link;
        free(ptr2);
        ptr2 = NULL;
    }else{
        while(position != 1){
            ptr1 = ptr2;
            ptr2 = ptr2->link;
            position--;
        }
        ptr1->link = ptr2->link;
        free(ptr2);
        ptr2 = NULL;
    }

    return head;
}

node *reverse(node *head){
    node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void count_node(node *head){
    int count = 0;
    if(head == NULL){
        printf("Lista vazia\n");
    }
    node *ptr;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("%d\n", count);
}

void print_dado(node *head){
    if(head == NULL){
        printf("Lista vazia");
    }
    node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->dado);
        ptr = ptr->link;
    }
}