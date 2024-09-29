#include<stdio.h>

int step = 1;

void TOH(int n, char S, char D, char A)
{
    if(n == 1)
    {
        printf("Step %d: Move disk from tower %d to tower %d\n", step++, S, D);
    }
    else
    {
        TOH(n-1, S, A, D);
        printf("Step %d: Move disk from tower %d to tower %d.\n", step++, S, D);
        TOH(n-1, A, D, S);
    }
}
int Factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else 
        return n * Factorial(n-1);
}
void Fibonacci(int n)
{
    int a = 0, b = 1, next;
    if(n == 0)
    {
        printf("Enter a positive number.\n");
        return;
    }
    printf("Fibonacci for %d terms:\n", n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            printf("%d ", a);
        else if(i == 1)
            printf("%d ", b);
        else {
            next = a + b;
            a = b;
            b = next;
            printf("%d ", next);
        }
    }
    printf("\n");
}

int main()
{
    int n, optn;
    int Tsource, Tdest, Taux;
    char contn;

    printf("Operations:\n 1- Tower of Hanoi.\n 2- Factorial.\n 3- Fibonacci.\n");

    do {
        printf("Enter option: ");
        scanf("%d", &optn);

        switch(optn)
        {
            case 1:
                printf("Enter number of rings: ");
                scanf("%d", &n);
                printf("Enter source tower: ");
                scanf("%d", &Tsource);
                printf("Enter destination tower: ");
                scanf("%d", &Tdest);

                TOH(n, Tsource, Tdest, Taux);
                printf("Total steps: %d\n", step-1);
                break;
            case 2:
                printf("Enter number for factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d is: %d", n, Factorial(n));
                break;
            case 3:
                printf("Enter number of terms in Fibonacci: ");
                scanf("%d", &n);
                Fibonacci(n);
                break;
            default:
                printf("\nIncorrect option.\nChoose from given options(1-3).\n");
                break;
        }
        printf("\nDo you want to continue(Y/N): ");
        scanf(" %c", &contn);
    }
    while(contn == 'Y' || contn == 'y');

    printf("\nProgram terminated successfully...\n\n");

    return 0;
}