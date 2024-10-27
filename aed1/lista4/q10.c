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

    for(i = 0; i < n; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &valor);
        node *no = create_node(valor);

        if(head == NULL){
            head = no;
            ptr = no;
        }else{
            ptr->next = no;
            ptr = ptr->next;
        }
    }

    return head;
}

int soma(node *head){
    node *ptr = head;
    int soma = 0;
        
    while(ptr != NULL){
        soma += ptr->data;
        ptr = ptr->next;
    }

    return soma;
}