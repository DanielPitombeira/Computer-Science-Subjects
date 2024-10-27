#include <stdio.h>

int buscaSequencial(int arr[], int n, int key, int positions[]) {
    int occurrences = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            positions[occurrences] = i;
            occurrences++;
        }
    }

    return occurrences;
}

int buscaBinaria(int arr[], int n, int key, int positions[]) {
    int occurrences = 0;
    int beggin = 0;
    int end = n - 1;

    while (beggin <= end) {
        int middle = beggin + (end - beggin) / 2;

        if (arr[middle] == key) {
            positions[occurrences] = middle;
            occurrences++;

            int left = middle - 1;
            while (left >= 0 && arr[left] == key) {
                positions[occurrences] = left;
                occurrences++;
                left--;
            }

            int right = middle + 1;
            while (right < n && arr[right] == key) {
                positions[occurrences] = right;
                occurrences++;
                right++;
            }

            return occurrences;
        } else if (arr[middle] < key) {
            beggin = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return occurrences;
}

int main() {
    int arror[] = {1, 2, 3, 4, 3, 5, 6, 3, 7, 8};
    int n = sizeof(arror) / sizeof(arror[0]);
    int key = 3;
    int positions[n];

    int occurrencesSeq = buscaSequencial(arror, n, key, positions);

    printf("chave %d encontrada em %d posições:\n", key, occurrencesSeq);
    for (int i = 0; i < occurrencesSeq; i++) {
        printf("Posição %d\n", positions[i]);
    }

    int occurrencesBin = buscaBinaria(arror, n, key, positions);

    printf("\n----------------------------\n");

    printf("chave %d encontrada em %d posições:\n", key, occurrencesBin);
    for (int i = 0; i < occurrencesBin; i++) {
        printf("Posição %d\n", positions[i]);
    }

    return 0;
}

