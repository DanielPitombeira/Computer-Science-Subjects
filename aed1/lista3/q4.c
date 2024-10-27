#include <stdio.h>

double media(int n1, int n2, int n3, char c){
    if(c == 'A') return (n1+n2+n3)/3;
    else if(c == 'P') return (5*n1 + 3*n2 + 2*n3)/(5+3+2);
}

int main(){
    double n1, n2, n3;
    char c;
    scanf("%lf%lf%lf", &n1, &n2, &n3);
    scanf("%*c%c", &c);
    printf("%.2lf", media(n1, n2, n3, c));

    return 0;
}