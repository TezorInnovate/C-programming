#include<stdio.h>
#include<stdlib.h>

int *array(int n)
{
    int *arr = malloc(n * sizeof(int));
    if(arr = NULL){
        printf("Memory allocation failed...\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    return arr;
}

void beginning(int new_element, int n, int arr[])
{
    for(int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = new_element;
    printf("New array: ");
    for(int i = 0; i <= n; i++){
        printf("%d ", arr[i]);
    } printf("\n\n");
}

void middle(int new_element, int arr[], int position, int n)
{
    n = n + 1;
    for(int i = n; i >= position; i--) {
        arr[i + 1] = arr[i];
        arr[position] = new_element; }
    printf("New array: ");
    for(int i = 0; i <= n; i++)
        printf("%d ", arr[i]);
     printf("\n\n");
}

void end(int new_element, int n, int arr[])
{
    // printf("Element inserted: %d\n", new_element);
    // n = n + 1;
    arr[n] = new_element;
    printf("New array: ");
    for(int i = 0; i <= n; i++){
        printf("%d ", arr[i]);
    } printf("\n\n");
}


int main()
{
    int n;
    int option;
    int new_element;
    int position;
    char repeat;

    printf("\n -> Insertion Option Menu:\n");
    printf("\nSelect the number for the task you want to perform.\n");
    printf("1- Beginning Insertion.\n2- Middle Insertion.\n3- End Insertion.\n");

    printf("\nCreate an array: \n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = array(n);
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
                    printf("Enter value to be inserted: ");
                    scanf("%d", &new_element);
                    *arr = realloc(arr, (n + 1) * sizeof(int));
                    beginning(new_element, n, arr);
                    break;

                case 2:
                    printf("Enter value to be inserted: ");
                    scanf("%d", &new_element);
                    printf("Which position do you want to insert at: ");
                    scanf("%d", &position);
                    if(position < 0 || position > n) {
                        printf("Invalid position...\n");
                        break;
                    }
                    *arr = realloc(arr, (n + 1) * sizeof(int));
                    middle(new_element, arr, position, n);
                    break;

                case 3:
                    printf("Enter value to be inserted: ");
                    scanf("%d", &new_element);
                    *arr = realloc(arr, (n + 1) * sizeof(int));
                    end(new_element, n, arr);
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

    free(arr);

    return 0;
}