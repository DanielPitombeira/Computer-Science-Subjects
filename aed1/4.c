#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cor[10];
    int valor;
}Carta;

typedef struct node{
    Carta carta;
    struct node* next;
}node;

void comprarCarta(node **head, node **last, Carta carta){
    node *new;

    new = (node *)malloc(sizeof(node));
    new->carta = carta;
    new->next = NULL;

    if(*head == NULL){
        *head = new;
        *last = new;
    }else{
        (*(*last)).next = new;
        *last = new;
    }
}

void mostrarCartas(node *head){
    node *ptr = head;
    int cont = 0;

    while(ptr != NULL){
        printf("cor: %s\nvalor: %d\n", ptr->carta.cor, ptr->carta.valor);
        ptr = ptr->next;
        cont++;
    }
    printf("%d cartas\n", cont);
}

void jogarCarta(node **head, Carta carta){
    node *ptr1, *ptr2;
    ptr1 = *head;
    ptr2 = *head;

    if(strcmp(ptr1->carta.cor, carta.cor) == 0){
        *head = ptr1->next;
        free(ptr1);
    }else{
        while(strcmp(ptr1->carta.cor, carta.cor) != 0){
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
        free(ptr1);
    }
}

void libera_memoria(node *head){
    node *ptr = head;

    while(ptr != NULL){
        ptr = ptr->next;
        free(head);
        head = ptr;
    }
}

int main(){
    int n;
    node *head = NULL;
    node *last = NULL;

    printf("quantas cartas: ");
    scanf("%d%*c", &n);

    for(int i = 0; i < n; i++){
        Carta carta;
        printf("Cor da carta: ");
        scanf("%s", carta.cor);
        printf("Valor da carta: ");
        scanf("%d%*c", &carta.valor);
        comprarCarta(&head, &last, carta);
    }

    mostrarCartas(head);

    printf("quantas cartas jogadas: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        Carta carta;

        printf("Cor da carta: ");
        scanf("%s", carta.cor);
        jogarCarta(&head, carta);
    }

    mostrarCartas(head);

    libera_memoria(head);

    return 0;
}