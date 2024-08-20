#include<stdio.h>
#include<stdlib.h>


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

    do {
        printf("Select the task (1-3): ");
        scanf("%d", &option);
        printf("\n");


        switch(option) 
            {
                case 1:
                    printf("Enter value to be inserted: ");
                    scanf("%d", &new_element);
                    for(int i = n; i >= 0; i--) {
                        array[i] = array[i - 1];
                    }
                    array[0] = new_element;
                    printf("New array: ");
                    for(int i = 0; i <= n; i++){
                        printf("%d ", array[i]);
                    } printf("\n\n");
                    break;

                case 2:
                    printf("Enter value to be inserted: ");
                    scanf("%d", &new_element);
                    printf("Which position do you want to insert at: ");
                    scanf("%d", &position);
                    n = n + 1;
                    for(int i = n; i >= position; i--) {
                        array[i] = array[i - 1];
                    }
                    array[position] = new_element;
                    printf("New array: ");
                    for(int i = 0; i <= n; i++){
                        printf("%d ", array[i]);
                    } printf("\n\n");
                    break;

                case 3:
                    printf("Enter value to be inserted: ");
                    scanf("%d", &new_element);
                    printf("Element inserted: %d\n", new_element);
                    n = n + 1;
                    array[n] = new_element;
                    printf("New array: ");
                    for(int i = 0; i <= n; i++){
                        printf("%d ", array[i]);
                    } printf("\n\n");
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

    free(array);

    return 0;
}