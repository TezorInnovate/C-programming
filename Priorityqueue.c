#include<stdio.h>

#define MAX 100
int element[MAX];
int priority[MAX];
int size = 0;

void enqueue(int val, int prio)
{
    if(size == (MAX-1))
    {
        printf("Queue is full.\n");
    }
    else
    {
        int i = size;
        element[i] = val;
        priority[i] = prio;
        size++;

        while(i > 0 && priority[i] > priority[i-1])
        {
            int tempVal = element[i];
            element[i] = element[i-1];
            element[i-1] = tempVal;

            int tempPri = priority[i];
            priority[i] = priority[i-1];
            priority[i-1] = tempPri;

            i--;
        }
    }
}
int dequeue()
{
    if(size == 0)
    {
        printf("Queue is empty.\nCannot delete further.\n");
    }
    else
    {
        int val = element[0];

        for(int i = 0; i < size-1; i++)
        {
            element[i] = element[i+1];
            priority[i] = priority[i+1];
        }
        size--;
        return val;
    }
}
void display()
{
    if(size == 0)
    {
        printf("Queue is empty.\nNothing to display.\n");
    }
    else
    {
        printf("Queue elements(value, priority):\n");
        for(int i = 0; i < size; i++)
        {
            printf(" (%d, %d) ", element[i], priority[i]);
        }
        printf("\n");
    }
}

int main()
{
    int optn, elem, prior;
    char contn;

    printf("Priority queue operations:\n 1- Enqueue.\n 2- Dequeue.\n 3- Display.\n");

    do {
        printf("Enter operation number: ");
        scanf("%d", &optn);
        switch(optn)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &elem);
                printf("Enter element priority: ");
                scanf("%d", &prior);
                enqueue(elem, prior);
                break;
            case 2:
                printf("Element dequeued: %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            default:
                printf("Incorrect operation selected.\nChoose from given options(1-3).\n");
                break;
        }
        printf("\nDo you want to continue(Y/N): ");
        scanf(" %c", &contn);
    }
    while(contn == 'Y' || contn == 'y');

    return 0;
}