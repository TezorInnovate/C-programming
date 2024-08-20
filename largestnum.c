#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    printf("\nCreate an array: \n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    printf("\nEnter the %d elements of the array: \n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }
    printf("The array is: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    } printf("\n\n");

    int length = sizeof(array) / sizeof(array[0]);
    int HighestValue = array[0];

    for(int i = 0; i < n; i++)
    {
        if(HighestValue > array[i])
        {
           continue; 
        } else {
            HighestValue = array[i];
        }
    }
    printf("The largest value is: %d", HighestValue);

    return 0;
}