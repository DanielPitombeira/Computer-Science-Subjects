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

    int menor;

    for(int i = 0; i < size; i++){
        for(int j)
    }

    return 0;
}