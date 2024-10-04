#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int arrLeft[n1], arrRight[n2];
    
    for(i = 0; i < n1; i++)
    {
        arrLeft[i] = a[left + i];
    }
    for(j = 0; j < n2; j++)
    {
        arrRight[j] = a[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while(i < n1 && j < n2)
    {
        if(arrLeft[i] <= arrRight[j])
        {
            a[k] = arrLeft[i];
            i++;
        }
        else {
            a[k] = arrRight[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        a[k] = arrLeft[i];
        i++;
        k++;
    }
    while(j < n2) {
        a[k] = arrRight[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
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
    mergeSort(arr, 0, n-1);
    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}