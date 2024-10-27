#include <stdio.h>

int main(){
    int v[5], m[2][2], i, j, z, num = 0;
    for(i = 0; i < 5; i++) scanf("%d", &v[i]);
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &m[i][j]);
            for(z = 0; z < 5; z++){
                if(m[i][j] == v[z])
                num++;
            }
        }
    }
    printf("%d\n", num);

    return 0;
}