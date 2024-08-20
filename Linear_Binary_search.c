#include<stdio.h>

int linear_search(int arr[], int n, int val)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    return  -1;
}

int binary_search(int arr[], int low, int high, int val)
{
    if(high >= low)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == val)
            return mid;
        if(arr[mid] > val)
            return binary_search(arr, low, mid-1, val);
        
        return binary_search(arr, mid+1, high, val);
    }
    return -1;
}

int main()
{
    int arr[100], n, val, index, optn, contn;

    printf("\nNote: array must be sorted...\n");
    printf("Create an array:\n");
    printf("\nEnter the number of elements (n) in the array: ");
    scanf("%d", &n);
    printf("\nEnter the %d elements of the array:\n", n);
    for(int i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nThe array created:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    } printf("\n\n");

    do {
        printf("Choose the search you want to perform:\n");
        printf(" 1- Linear search.\n 2- Binary search.\n");
        printf("Enter option: ");
        scanf("%d", &optn);

        switch(optn)
        {
            case 1:
                printf("\nLinear search:\n");
                printf("Enter the value you want to search: ");
                scanf("%d", &val);
                index = linear_search(arr, n, val);
                if(index == -1)
                {
                    printf("Element is not present in given array.\n");
                }
                else 
                {
                    printf("The value %d is present in array at index: %d\n", val, index);
                }
                break;
            case 2:
                printf("\nBinary search:\n");
                printf("Enter the value you want to search: ");
                scanf("%d", &val);
                index = binary_search(arr, 0, n-1, val);
                if(index == -1)
                {
                    printf("Element is not present in given array.\n");
                }
                else
                    printf("The value %d is present in array at index: %d\n", val, index);
                break;
            default:
                printf("Incorrect option...\nPlease choose from provided menu.\n");
                break;
        }
        printf("\nDo you want to continue(Y/N): ");
        scanf(" %c", &contn);
    }
    while(contn == 'Y' || contn == 'y');

    printf("\nProgram terminated successfully...\n\n");

    return 0;
}