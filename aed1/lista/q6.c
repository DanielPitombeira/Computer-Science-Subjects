#include <stdio.h>
#include <string.h>

void insertionSort(char nomes[][100], int n) {
    int i, j;
    char chave[100];
    
    for (i = 1; i < n; i++) {
        strcpy(chave, nomes[i]);
        j = i - 1;

        while (j >= 0 && strlen(nomes[j]) > strlen(chave)) {
            strcpy(nomes[j + 1], nomes[j]);
            j = j - 1;
        }

        strcpy(nomes[j + 1], chave);
    }
}

void selectionSort(char nomes[][100], int n) {
    int i, j, index;
    char temp[100];

    for (i = 0; i < n - 1; i++) {
        index = i;

        for (j = i + 1; j < n; j++) {
            if (strlen(nomes[j]) < strlen(nomes[index]))
                index = j;
        }

        if (index != i) {
            strcpy(temp, nomes[i]);
            strcpy(nomes[i], nomes[index]);
            strcpy(nomes[index], temp);
        }
    }
}

int main() {
    int n, i;
    printf("Quantidade de nomes: ");
    scanf("%d", &n);

    char nomes[n][100];

    for (i = 0; i < n; i++) {
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", nomes[i]);
    }

    insertionSort(nomes, n);

    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    printf("\n");
    printf("-------------------------------------------");
    printf("\n\n");

    selectionSort(nomes, n);

    for (i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
