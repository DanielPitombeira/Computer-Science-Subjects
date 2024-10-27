#include <stdio.h>
#include <stdlib.h>

int main(){
    int maior, i, n, *v;
    scanf("%d", &n);
    v = calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
        if(i == 0) maior = v[i];
        else if(v[i] > maior) maior = v[i];
    }
    printf("%d\n", maior);
    free(v);

    return 0;
}