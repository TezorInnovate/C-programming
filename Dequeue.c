#include<stdio.h>

#define MAX 100
int dequeue[MAX];
int F = -1;
int R = -1;

void insertFront(int val)
{
    if((F == 0 && R == MAX-1) || (F == R+1)) {
        printf("Queue is full.\n");
        return;
    }
    
    if(F == -1)
    {
        F = R = 0;
    }
    else if(F == 0)
    {
        F = MAX-1;
    }
    else {
        F--;
    }
    dequeue[F] = val;
}
void insertRear(int val)
{
    if((F == 0 && R == MAX-1) || (F == R+1)) {
        printf("Queue is full.\n");
        return;
    }
    
    if(F == -1)
    {
        F = R = 0;
    }
    else if(R == MAX-1)
    {
        R = 0;
    }
    else
    {
        R++;
    }
    dequeue[R] = val;
}
int deleteFront()
{
    if(F == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int val = dequeue[F];
    if(F == R)
    {
        F = R = -1;
    }
    else if(F = MAX-1)
    {
        F = 0;
    }
    else
    {
        F++;
    }
    return val;
}
int deleteRear()
{
    if(F == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int val = dequeue[R];
    if(F == R)
    {
        F = R = -1;
    }
    else if(R == 0)
    {
        R = MAX-1;
    }
    else
    {
        R--;
    }
    return val;
}
void display()
{
    if(F == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    int i = F;
    if(F <= R)
    {
        while(i <= R)
        {
            printf("%d ", dequeue[i++]);
        }
    }
    else
    {
        while(i <= MAX-1)
        {
            printf("%d ", dequeue[i++]);
        }
        i = 0;
        while(i <= R)
        {
            printf("%d ", dequeue[i++]);
        }
    }
    printf("\n");
}

int main()
{
    int type, optn, val, side;
    char contn;

    printf("Dequeue types:\n 1- Input restricted.\n 2- Output restricted.\n");
    printf("Enter type: ");
    scanf("%d", &type);

    if(type == 1)
    {
        printf("Dequeue operations:\n 1- Input front/rear.\n 2- Delete rear.\n 3- Delete front.\n 4- Display.\n");
        printf("Choose input side(front-1/rear-2): ");
        scanf("%d", &side);
        do {
            printf("Enter option: ");
            scanf("%d", &optn);
            switch(optn)
            {
                case 1:
                    printf("Enter value to input: ");
                    scanf("%d", &val);
                    if(side == 1)
                        insertFront(val);
                    else if(side == 2)
                        insertRear(val);
                    break;
                case 2:
                    printf("Deleted rear: %d", deleteRear());
                    break;
                case 3:
                    printf("Deleted front: %d", deleteFront());
                    break;
                case 4: 
                    display();
                    break;
                default:
                    printf("Incorrect option.\n");
                    break;
            }
            printf("Do you want to continue(Y/N): ");
            scanf(" %c", &contn);
        }
        while(contn == 'Y' || contn == 'y');
    }
    else if(type == 2)
    {
        printf("Dequeue operations:\n 1- Input front.\n 2- Input rear.\n 3- Delete front/rear\n 4- Display.\n");
        printf("Choose delete side(front-1/rear-2): ");
        scanf("%d", &side);
        do {
            printf("Enter option: ");
            scanf("%d", &optn);
            switch(optn)
            {
                case 1:
                    printf("Enter value to input: ");
                    scanf("%d", &val);
                    insertFront(val);
                    break;
                case 2:
                    printf("Enter value to input: ");
                    scanf("%d", &val);
                    insertRear(val);
                    break;
                case 3:
                    if(side == 1)
                        printf("Deleted front: %d", deleteFront());
                    else if(side == 2)
                        printf("Deleted rear: %d", deleteRear());
                    break;
                case 4: 
                    display();
                    break;
                default:
                    printf("Incorrect option.\n");
                    break;
            }
            printf("Do you want to continue(Y/N): ");
            scanf(" %c", &contn);
        }
        while(contn == 'Y' || contn == 'y');
    }

    return 0;
}