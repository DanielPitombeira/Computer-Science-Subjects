#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int chave, j;

    for(int i = 1; i < n; i++){
        chave = v[i];

        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = chave;
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}