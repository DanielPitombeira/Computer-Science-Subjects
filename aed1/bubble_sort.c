#include <stdio.h>//3 5 4 1 9 6 7 2
#include <stdlib.h>

int main(){
    int *v, size;

    printf("tamanho do vetor: \n");
    scanf("%d", &size);

    v = malloc(size*sizeof(int));

    for(int i = 0; i < size; i++){
        scanf("%d", &v[i]);
    }

    int aux;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    for(int i = 0; i < size; i++){
        printf("%d\n", v[i]);
    }

    free(v);

    return 0;
}