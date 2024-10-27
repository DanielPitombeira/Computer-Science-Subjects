#include <stdio.h>

int main(){
    double sal_min, sal;
    printf("Informe o salario minimo: ");
    scanf("%lf", &sal_min);
    printf("Informe o salario da pessoa: ");
    scanf("%lf", &sal);
    printf("A pessoa ganha %.1lf salarios minimos\n", sal/sal_min);

    return 0;
}
