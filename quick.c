#include <stdio.h>

#define MAX 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int P = partition(a, low, high);
        quickSort(a, low, P-1);
        quickSort(a, P+1, high);
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n;
    
    printf("Enter numbr of elements of array: ");
    scanf("%d", &n);
    printf("Create array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, n - 1);
    printf("\nSorted array:\n");
    printArray(arr, n);
    return 0;
}