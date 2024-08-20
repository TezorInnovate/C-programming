#include<stdio.h>
#define MAX 50

void array(int num, int n, int m, int a[MAX][MAX])
{
    printf("Enter the elements of the %d array:\n", num);
    for(int i = 0;i < n; i++)
    {
        printf("Row %d of array:\n", i);
        for(int j = 0; j < m; j++)
        {
            printf("Element %d: ", j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nArray %d created:\n", num);
    for(int i = 0; i < n; i++)
    {
        printf("   ");
        for(int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    } printf("\n");
}
void addition(int n, int m, int a1[MAX][MAX], int a2[MAX][MAX])
{
    int a_result[MAX][MAX];
    for(int i = 0; i < n; i++)
    {
        printf(" ");
        for(int j = 0; j < m; j++)
        {
            a_result[i][j] = a1[i][j] + a2[i][j];   
            printf("%d ", a_result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void subtraction(int n, int m, int a1[MAX][MAX], int a2[MAX][MAX])
{
    int a_result[MAX][MAX];
    for(int i = 0; i < n; i++)
    {
        printf(" ");
        for(int j = 0; j < m; j++)
        {
            a_result[i][j] = a1[i][j] - a2[i][j];   
            printf("%d ", a_result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void multiplication(int n, int m, int a1[MAX][MAX], int a2[MAX][MAX])
{
    int a_result[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a_result[i][j] = 0;
 
            for (int k = 0; k < n; k++) {
                a_result[i][j] += a1[i][k] * a2[k][j];
            }
 
            printf("%d\t", a_result[i][j]);
        }
        printf("\n");
    }
}
void transpose(int n, int m, int a[MAX][MAX])
{
    int a_result[MAX][MAX];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a_result[i][j] = a[j][i];
            printf("%d ", a_result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void diagonal_Sum(int n, int m, int a[MAX][MAX], int optn)
{
    int sum = 0;
    if(optn == 1)
    {
        for(int i = 0; i < n ; i++)
            for(int j = 0; j < m; j++)
            {
                if(i == j)
                {
                    sum += a[i][j];
                }
            }
    }
    else
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int c = i + j;
                if(c == (n-1))
                {
                    sum += a[i][j];
                }
            }
    }
    printf("Sum of diagonal is: %d\n\n", sum);
}
void upper_Triangle(int n, int m, int a[MAX][MAX])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        m--;
        printf("\n");
    }
    printf("\n");
}
void lower_Triangle(int n, int m, int a[MAX][MAX])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int c = i + j;
            if(c > (n-1))
            {
                printf("%d ", a[i][j]);
            }
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    int option, arrChoice;
    int n, m, num, transpose_of, up_tri, lo_tri, optn;
    int a1[MAX][MAX], a2[MAX][MAX];
    char exit;

    //Creating 2 2D arrays from user input:
    printf("Create array 1:\n");
    printf("Enter number of rows of array: ");
    scanf("%d", &n);
    printf("Enter number of columns of array: ");
    scanf("%d", &m);
    array(1, n, m, a1);

    printf("Create array 2:\n");
    array(2, n, m, a2);

    //Printing menu and taking option input:
    printf("\n****** 2D Array Operations ******\n\n");
    printf("Choose the operation you want to perform:\n");
    printf(" 0- Create new arrays.\n 1- Addition.\n 2- Subtraction.\n 3- Multiplication.\n 4- Transpose.\n 5- Diagonal sum.\n 6- Upper triangle.\n 7- Lower triangle.");
    
    
    do {
        printf("\nSelect operation: ");
        scanf("%d", &option);
        printf("\n");

        switch(option)
        {
            case 0:
                printf("Create array 1:\n");
                printf("Enter number of rows of array: ");
                scanf("%d", &n);
                printf("Enter number of columns of array: ");
                scanf("%d", &m);
                array(1, n, m, a1);

                printf("Create array 2:\n");
                array(2, n, m, a1);
                break;
            case 1:
                addition(n, m, a1, a2);
                break;
            case 2:
                subtraction(n, m, a1, a2);
                break;
            case 3:
                multiplication(n, m, a1, a2);
                break;
            case 4:
                printf("Choose array to transpose(1/2): ");
                scanf("%d", &transpose_of);
                if(transpose_of == 1)
                {
                    transpose(n, m, a1);
                }
                else
                {
                    transpose(n, m, a2);
                }
                break;
            case 5:
                printf("Choose diagonal:\n");
                printf(" 1- Decreasing diagonal.\n 2- Increasing diagonal.\n");
                printf("Enter option: ");
                scanf("%d", &optn);
                printf("Choose array to sum the diagonal of(1/2): ");
                scanf("%d", &arrChoice);
                if(arrChoice == 1)
                {
                    diagonal_Sum(n, m, a1, optn);
                }
                else
                {
                    diagonal_Sum(n, m, a2, optn);
                }
                break;
            case 6:
                printf("Choose array to print upper triangle of(1/2): ");
                scanf("%d", &up_tri);
                if(up_tri == 1)
                {
                    upper_Triangle(n, m, a1);
                }
                else
                {
                    upper_Triangle(n, m, a2);
                }
                break;
            case 7:
                printf("Choose array to print lower triangle of(1/2): ");
                scanf("%d", &lo_tri);
                if(lo_tri == 1)
                {
                    lower_Triangle(n, m, a1);
                }
                else
                {
                    lower_Triangle(n, m, a2);
                }
                break;
            default:
                printf("Wrong option...\n");
                printf("Choose from given options (1 - 7).\n\n");
                break;
        }
        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &exit);
    }
    while(exit == 'Y' || exit == 'y');

    printf("\nProgram terminated successfully...\n\n");

    return 0;
}