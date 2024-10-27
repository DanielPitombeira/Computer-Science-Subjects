#include <stdio.h>
#include <stdlib.h>

int main(){
    int x1, y1, *x2, *y2;
    scanf("%d %d", &x1, &y1);
    x2 = &x1;
    y2 = &y2;
    if(x2 > y2) printf("%p\n", x2);
    else if(y2 > x2) printf("%p\n", y2);
    free(x2);
    free(y2);

    return 0;
}