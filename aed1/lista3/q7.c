#include <stdio.h>

int soma(int n){
    if(n == 0) return 0;
    return soma(n-1) + n; 
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", soma(n));

    return 0;
}