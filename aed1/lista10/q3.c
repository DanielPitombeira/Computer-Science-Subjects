#include <stdio.h>
#include "q3.h"

int main(){
    int op, quantidade = 0;
    Produto produto;

    while(1){
        printf("Escolha a operacao a ser realizada: \n");
        printf("1- Adicionar um novo produto ao estoque.\n");
        printf("2- Vender um produto do estoque.\n");
        printf("3- Verifica se o estoque esta vazio.\n");
        printf("4- Exibir o produto no topo do estoque.\n");
        printf("5- Exibir a quantidade total de produtos em estoque.\n");
        printf("6- Sair do programa.\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Codigo: ");
                scanf("%d", &produto.codigo);
                printf("Nome do produto: ");
                scanf("%*c%[^\n]", produto.nome);
                printf("Quantidade: ");
                scanf("%d", &produto.quantidade);
            
                push(produto);
                quantidade++;
                break;
            case 2:
                produto = pop();
                if(quantidade > 0) 
                    quantidade--;
                printf("Codigo: %d\n", produto.codigo);
                printf("Nome: %s\n", produto.nome);
                printf("Quantidade: %d\n", produto.quantidade);
                break;
            case 3:
                if(isEmpty() == 1)
                    printf("Estoque vazio\n");
                else if(isEmpty() == 0){
                    printf("Estoque nao vazio\n");
                }
                break;
            case 4:
                top();
                break;
            case 5:
                printf("Quantidade: %d\n", quantidade);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("opcao invalida\n");
                break;
        }
    }

    return 0;
}