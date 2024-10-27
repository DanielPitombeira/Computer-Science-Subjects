#include <stdio.h>
#include "q10.h"

int main(){
    char string[189820];

    printf("Digite a palavra: \n");
    scanf("%s", string);

    push(string);

    palindromo();

    return 0;
}
