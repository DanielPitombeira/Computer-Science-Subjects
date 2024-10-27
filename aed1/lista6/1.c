#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void create_list(struct ListNode **head, struct ListNode **last, int val){
    struct ListNode *node;

    node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
        *last = node;
    }else{
        (*last)->next = node;
        *last = node;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ptr1, *ptr2, *head = NULL, *last = NULL;
    int sum, prevsum = 0;
    ptr1 = l1;
    ptr2 = l2;

    while(ptr1 != NULL || ptr2 != NULL){
        sum = prevsum;
        if(ptr1 != NULL){
            sum += ptr1->val;
            ptr1 = ptr1->next;
        }

        if(ptr2 != NULL){
            sum += ptr2->val;
            ptr2 = ptr2->next;
        }

        prevsum = sum / 10;
        sum = sum % 10;
        create_list(&head, &last, sum);
    }

    return head;
}

void print_list(struct ListNode *head){
    struct ListNode *ptr = head;

    while(ptr != NULL){
        printf("valor: %d\n", ptr->val);
        ptr = ptr->next;
    }
}

int main(){
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *head3 = NULL;
    struct ListNode *last1 = NULL, *last2 = NULL;
    int n, val;

    printf("quantos digitos(1° lista): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("valor: ");
        scanf("%d", &val);
        create_list(&head1, &last1, val);
    }

    printf("quantos digitos(2° lista): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("valor: ");
        scanf("%d", &val);
        create_list(&head2, &last2, val);
    }

    head3 = addTwoNumbers(head1, head2);
    print_list(head3);

    return 0;
}