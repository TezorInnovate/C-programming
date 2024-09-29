#include <stdio.h>

#define MAX 100

void selectionSort(int arr[MAX], int n) {
    for (int i = 0; i < n - 1; i++) {

        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[MAX];
    int n;
    
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Create array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    selectionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}