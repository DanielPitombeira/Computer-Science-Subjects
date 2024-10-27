#include <stdio.h>
#include <string.h>

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1), j;
    char temp;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
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

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char str[100];
    
    printf("Digite uma string: ");
    scanf("%s", str);
    
    int length = strlen(str);
    
    quickSort(str, 0, length - 1);
    
    printf("String ordenada: %s\n", str);
    
    return 0;
}

