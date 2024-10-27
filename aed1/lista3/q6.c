#include <stdio.h>

int operacao(int n){
    if(n == 1) return 1;
    return 2*operacao(n/2) + n;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", operacao(n));

    return 0;
}