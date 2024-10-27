#include <stdio.h>

int potencia(int x, int n, int resul){
    if(n == 0) return 1;
    if(n == 1) return resul;
    else return(potencia(x, --n, resul * x));
}

int main(){
    int x, n, resul;
    scanf("%d %d", &x, &n);
    resul = x;
    printf("%d\n",potencia(x, n, resul));

    return 0;
}