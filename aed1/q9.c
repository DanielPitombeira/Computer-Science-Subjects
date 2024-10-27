#include <stdio.h>

int main(){
    int x1, *x2;
    double y1, *y2;
    scanf("%d %lf", &x1, &y1);
    x2 = &x1;
    y2 = &y1;
    printf("Antes\nx1: %d , y1: %lf\n", x1, y1);
    *x2 = 5;
    *y2 = 6;
    printf("Depois\nx1: %d , y1: %lf\n", x1, y1);

    return 0;
}