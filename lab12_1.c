#include<stdio.h>

#define MAX 100

void bubble_sort(int n, int a[MAX])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n-1); j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int n, arr[MAX];
    
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array created:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nBubble sort:\n");
    
    bubble_sort(n, arr);
    
    
    return 0;
}