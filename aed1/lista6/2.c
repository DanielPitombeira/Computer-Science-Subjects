#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print(struct ListNode *head){
    struct ListNode *ptr;
    ptr = head;

    while(ptr != NULL){
        printf("valor: %d\n", ptr->val);
        ptr = ptr->next;
    }
}

void create_list(struct ListNode **head, struct ListNode **last, int val){
    struct ListNode *ptr, *node;
    ptr = *head;

    node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
        *last = *head;
    }else{
        (*last)->next = node;
        *last = (*last)->next;
    }
}

struct ListNode* reverse_list(struct ListNode *head){
    struct ListNode *head2 = NULL, *ptr1, *ptr2;
    ptr1 = head;

    while(ptr1 != NULL){
        ptr2 = malloc(sizeof(struct ListNode));
        ptr2->val = ptr1->val;
        ptr2->next = head2;
        head2 = ptr2;
        ptr1 = ptr1->next;
    }

    return head2;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *head2 = NULL, *ptr2, *ptr3;
    int i;

    head2 = reverse_list(head);

    ptr2 = head2;
    if(n == 1){
        head2 = head2->next;
        free(ptr2);
    }else{
        ptr3 = head2->next;
        for(i = 0; i < n-2; i++){
            ptr2 = ptr3;
            ptr3 = ptr3->next;
        }
        ptr2->next = ptr3->next;
        free(ptr3);
    }

    head2 = reverse_list(head2);

    print(head2);
}

int main(){
    struct ListNode *head = NULL;
    struct ListNode *last = NULL;
    int n;

    printf("quantos digitos? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int val;
        printf("valor: ");
        scanf("%d", &val);

        create_list(&head, &last, val);       
    }

    printf("valor de n:");
    scanf("%d", &n);
    removeNthFromEnd(head, n);

    return 0;
}