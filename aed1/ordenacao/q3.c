#include <stdio.h>

void Merge(int *v1, int esquerda, int *v2, int direita, int *v, int n){
    int i, j, k;

    i = j = k = 0;

    while(i < esquerda && j < direita){
        if(v1[i] <= v2[j]){
            v[k] = v1[i];
            i++;
        }else{
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < esquerda){
        v[k] = v1[i];
        i++;
        k++;
    }

    while(j < direita){
        v[k] = v2[j];
        j++;
        k++;
    }
}

void MergeSort(int *v, int n){
    int meio, esquerda, direita;

    if(n < 2) 
        return;
    if(n % 2 == 0)
        meio = n / 2;
    else
        meio = (n + 1) / 2;
    esquerda = meio;
    direita = n - meio;

    int v1[esquerda], v2[direita], k = 0;

    for(int i = 0; i < esquerda; i++)
        v1[i] = v[k++];

    for(int i = 0; i < direita; i++)
        v2[i] = v[k++];

    MergeSort(v1, esquerda);
    MergeSort(v2, direita);
    Merge(v1, esquerda, v2, direita, v, n);
}

int main(){
    int n;

    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    MergeSort(v, n);

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\n");

    return 0;
}
