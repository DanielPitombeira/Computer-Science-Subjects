#include <stdio.h>
#define MAX_CARTAS 40

typedef struct CartaUno {
    int cor;
    int numero;
} CartaUno;

void insere_carta(CartaUno *meuconjunto, int *pos);
int contarCartasVerdes(CartaUno *meuconjunto, int num);

int main(){
    CartaUno meuConjunto[MAX_CARTAS];
    int pos = 0, num = 0;

    insere_carta(meuConjunto, &pos);
    num++;
    insere_carta(meuConjunto, &pos);
    num++;
    insere_carta(meuConjunto, &pos);
    num++;
    insere_carta(meuConjunto, &pos);
    num++;
    insere_carta(meuConjunto, &pos);
    num++;
    
    printf("tem %d cartas verdes\n", contarCartasVerdes(meuConjunto, num));

    return 0;
}

void insere_carta(CartaUno *meuconjunto, int *pos){
    CartaUno carta;

    printf("Cor da carta: ");
    scanf("%d", &carta.cor);
    printf("numero da carta: ");
    scanf("%d", &carta.numero);

    meuconjunto[*pos].cor = carta.cor;
    meuconjunto[*pos].numero = carta.numero;
    *pos = *pos + 1;
}

int contarCartasVerdes(CartaUno *meuconjunto, int num){
    if(num == 0) 
        return 0;
    else if(meuconjunto[num - 1].cor == 2){
        int conta = 0;

        conta += contarCartasVerdes(meuconjunto, num - 1) + 1;

        return conta;
    }
    else{
        return contarCartasVerdes(meuconjunto, num - 1);
    }
}
