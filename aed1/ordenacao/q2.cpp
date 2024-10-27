#include <stdio.h>

int particao(int v[], int inicio, int fim){
    int pivo, i, swap, pIndex;

    pivo = v[fim];
    pIndex = inicio;

    for(i = inicio; i < fim; i++){
        if(v[i] <= pivo){
            swap = v[i];
            v[i] = v[pIndex];
            v[pIndex] = swap;
            pIndex++;
        }
    }
    swap = v[fim];
    v[fim] = v[pIndex];
    v[pIndex] = swap;

    return pIndex;
}

void QuickSort(int *v, int inicio, int fim){
    int pIndex;
    if(inicio < fim){
        pIndex = particao(v, inicio, fim);

        QuickSort(v, inicio, pIndex - 1);
        QuickSort(v, pIndex + 1, fim);
    }
}

int main(){
    int n;

    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    QuickSort(v, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
