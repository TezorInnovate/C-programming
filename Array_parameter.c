#include<stdio.h>
#define MAX 50

int array_multiple(int n, int m, int x, int arr[MAX][MAX])
{
    int new_arr[MAX][MAX];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            new_arr[i][j] = arr[i][j] * x;
            printf("%d ", new_arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, x;
    int arr[MAX][MAX];

    printf("Create a 2-D array:\n");
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);
    printf("Enter the elements of the array:\n");
    for(int i = 0;i < n; i++)
    {
        printf("Row %d of array:\n", i);
        for(int j = 0; j < m; j++)
        {
            printf("Element %d: ", j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nArray created:\n");
    for(int i = 0; i < n; i++)
    {
        printf("   ");
        for(int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    } printf("\n");

    printf("Enter the multiple value: ");
    scanf("%d", &x);
    array_multiple(n, m, x, arr);

    return 0;
}