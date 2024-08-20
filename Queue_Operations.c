#include<stdio.h>

#define MAX 10
int Q[MAX];
int F = -1, R = -1;

void enqueue(int val)
{
    if(R == (MAX - 1))
    {
        printf("Queue is full.\n");
    }
    else if(F == -1 && R == -1)
    {
        F = 0;
        R = 0;
        printf("\nEnter value to add to queue: ");
        scanf("%d", &val);
        Q[R] = val;
        printf("%d added to queue.\n", val);
    }
    else
    {
        R++;
        printf("\nEnter value to add to queue: ");
        scanf("%d", &val);
        Q[R] = val;
        printf("%d added to queue.\n", val);
    }
}
void dequeue()
{
    if(F == -1 && R == -1)
    {
        printf("Queue is already empty.\n");
    }
    else if(F == (MAX - 1) && R == (MAX - 1))
    {
        F = -1;
        R = -1;
    }
    else
    {
        printf("%d deleted from queue.\n", Q[F]);
        F++;
    }
}
void display()
{
    printf("\nDisplay Queue:\n");
    printf("  ");
    for(int i = F; i <= R; i++)
        printf("%d ", Q[i]);
    printf("\n");
}

int main()
{
    int val, optn;
    char contn;

    printf("\nQueue operations:\n 1- Insert in queue.\n 2- Delete from queue.\n 3- Display queue.\n");
    
    do {
        printf("Enter option (1-3): ");
        scanf("%d", &optn);

        switch(optn)
        {
            case 1:
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Incorrect option.\nChoose from given options (1-4).\n");
                break;
        }
        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c", &contn);
    }
    while(contn == 'Y' || contn == 'y');

    printf("\nProgram terminated successfully...\n\n");

    return 0;
}