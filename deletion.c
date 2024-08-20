#include<stdio.h>
#include<stdlib.h>

 void beginning(int n, int arr[])
{
    for(int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
    printf("New array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    } printf("\n\n");
}

void middle(int arr[], int position, int n)
{
    for(int i = position; i <= n - 1; i++) {
        arr[i] = arr[i + 1];
        }
        n = n - 1;
    printf("New array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
     printf("\n\n");
}

void end(int n, int arr[])
{
    n = n - 1;
    printf("New array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    } printf("\n\n");
}
 
 int main()
 {
    int arr[100];
    int n;
    int option;
    int position;
    char repeat;

    printf("\n -> Deletion Option Menu:\n");
    printf("\nSelect the number for the task you want to perform.\n");
    printf("1- First Element Deletion.\n2- Middle Element Deletion.\n3- Last Element Deletion.\n");

    printf("\nCreate an array: \n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the %d elements of the array: \n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("The array is: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");

    do {
        printf("Select the task (1-3): ");
        scanf("%d", &option);
        printf("\n");

        switch(option) 
            {
                case 1:
                    beginning(n, arr);
                    n = n - 1;
                    break;

                case 2:
                    printf("Which position element do you want to delete: ");
                    scanf("%d", &position);
                    if(position < 0 || position > n) {
                        printf("Invalid position...\n");
                        break;
                    }
                    middle(arr, position, n);
                    n = n - 1;
                    break;

                case 3:
                    end(n, arr);
                    break;

                default:
                    printf("Selected option does not exist.\n");
                    printf("Please choose from 1-3 only...\n\n");
                    break;
            }
            printf("Do you want to continue (Y/N): ");
            scanf(" %c", &repeat);
            printf("\n");
    }
    while(repeat == 'Y' || repeat == 'y');

    return 0;
 }