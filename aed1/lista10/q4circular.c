#include "q4.h"

node* begin;
node* end;

void lista_vazia(){
    if(begin == NULL){
        printf("Lista vazia\n");
    } 
}

void inserir_inicio(int num){
    node* no;

    no = malloc(sizeof(node));
    no->data = num;
    no->next = NULL;

    if(begin == NULL && end == NULL){
        begin = end = no;
        end->next = begin;
    }else{
        
    }
}

void inserir_final(int num){

}