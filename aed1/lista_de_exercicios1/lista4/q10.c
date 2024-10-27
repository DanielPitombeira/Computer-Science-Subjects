#include <stdio.h>
#include <stdlib.h>
#include "q10.h"

node *create_node(int valor){
    node *no = malloc(sizeof(node));

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

int soma(node *head){
    node *ptr = head->next;
    int soma = 0;
        
    while(ptr != NULL){
        soma += ptr->data;
        ptr = ptr->next;
    }

    return soma;
}