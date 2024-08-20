#include<stdio.h>
#include<stdlib.h>

void search();

int main() 
{
    int n;

    //Creating an array.
    printf("\n****** Binary search of Array ******\n\n");
    printf("Creating an Array:\n");
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

    return 0;
}

