/*
funcao imprime
void imprime (celula *le) {
   if (le != NULL) {
      printf ("%d\n", le->conteudo);
      imprime (le->prox);
   }
}

cria lista recursiva
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createLinkedList(int* array, int size, int index) {
    if (index >= size) {
        return NULL;
    }
    
    struct Node* newNode = createNode(array[index]);
    newNode->next = createLinkedList(array, size, index + 1);
    
    return newNode;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    freeLinkedList(head->next);
    free(head);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    
    struct Node* head = createLinkedList(array, size, 0);
    
    printf("Lista Encadeada: ");
    printLinkedList(head);
    
    freeLinkedList(head);
    
    return 0;
}


intercala duas listas ordenadas
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node* mergedHead = NULL;

    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeLists(head1, head2->next);
    }

    return mergedHead;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    freeLinkedList(head->next);
    free(head);
}

int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    struct Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    printf("Lista 1: ");
    printLinkedList(head1);

    printf("Lista 2: ");
    printLinkedList(head2);

    struct Node* mergedHead = mergeLists(head1, head2);

    printf("Lista Intercalada: ");
    printLinkedList(mergedHead);

    freeLinkedList(mergedHead);

    return 0;
}
*/