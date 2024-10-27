#include <stdio.h>

int maior(int v[], int n, int m){
    if(n == 0) return m;
    else if(m < v[--n]){
        m = v[n];
    }
    return maior(v, n, m);
}

int main(){
    int n, i, m;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    m = v[--i];
    printf("%d\n", maior(v, (--n), m));

    return 0;
}