#include <stdio.h>
#include <math.h>

double distancia(double x1, double y1, double x2, double y2);

int main(){
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    printf("%.2lf\n", distancia(x1,y1,x2,y2));

    return 0;
}

double distancia(double x1, double y1, double x2, double y2){
    return (sqrt(pow((x1-x2), 2) + pow((y1-y2), 2)));
}