#include <stdio.h>

int verifica(int x1){
    if(x1 % 2 == 0) return 1;
    else return 0;
}

int main(){
    int x1;
    scanf("%d", &x1);
    printf("%d\n", verifica(x1));

    return 0;
}