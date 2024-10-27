#include <stdio.h>
#include <stdlib.h>

void merge(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3) {
        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            result[i + j + k] = arr1[i];
            i++;
        } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
            result[i + j + k] = arr2[j];
            j++;
        } else {
            result[i + j + k] = arr3[k];
            k++;
        }
    }

    while (i < n1) {
        result[i + j + k] = arr1[i];
        i++;
    }

    while (j < n2) {
        result[i + j + k] = arr2[j];
        j++;
    }

    while (k < n3) {
        result[i + j + k] = arr3[k];
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        int n1 = middle - left + 1;
        int n2 = right - middle;
        int leftArr[n1], rightArr[n2];

        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[middle + 1 + j];
        }

        merge(leftArr, rightArr, NULL, n1, n2, 0, arr + left);
    }
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6, 8};
    int arr3[] = {0, 9, 10, 11};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    int result[n1 + n2 + n3];

    mergeSort(result, 0, n1 + n2 + n3 - 1);

    printf("Vetor intercalado e ordenado: ");
    for (int i = 0; i < n1 + n2 + n3; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

