#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    unsigned int Matricula;
    float Nota;
} Aluno;

int partition(Aluno arr[], int low, int high) {
    float pivot = arr[high].Nota;
    int i = (low - 1);
    Aluno temp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].Nota >= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(Aluno arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(Aluno arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Aluno leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].Matricula <= rightArr[j].Matricula) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(Aluno arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int N;
    printf("Quantidade de alunos: ");
    scanf("%d", &N);

    Aluno *alunos = (Aluno *)malloc(N * sizeof(Aluno));

    for (int i = 0; i < N; i++) {
        printf("Digite a matrícula e a nota do aluno %d: ", i + 1);
        scanf("%u%f", &alunos[i].Matricula, &alunos[i].Nota);
    }

    quickSort(alunos, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("Matrícula: %u, Nota: %.2f\n", alunos[i].Matricula, alunos[i].Nota);
    }

    printf("\n----------------------------\n");
    mergeSort(alunos, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("Matrícula: %u, Nota: %.2f\n", alunos[i].Matricula, alunos[i].Nota);
    }

    free(alunos);
    return 0;
}