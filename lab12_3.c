#include<stdio.h>

#define MAX 100

void insertionSort(int n, int arr[MAX])
{
    for(int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n, arr[MAX];
    
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
    
    printf("\nInsertion sort:\n");
    insertionSort(n, arr);
    
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}