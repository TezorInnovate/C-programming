#include<stdio.h>

#define MAX 5
int stack[MAX];
int top = -1;

void PUSH(int val)
{
    printf("\nEnter value to push to stack: ");
    scanf("%d", &val);

    if(top == (MAX - 1))
    {
        printf("\nStack is full.\nCannot PUSH new value to stack.\n");
    }
    else
    {
        top++;
        stack[top] = val;
        printf("%d pushed to stack.\n", val);
    }
}
void POP()
{
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}
void display()
{
    if(top == -1)
    {
        printf("Stack is empty.\nNo Display...\n");
    }
    else
    {
        printf("Stack Display:\n");
        for(int i = top; i >= 0; i--)
        {
            printf("    %d\n", stack[i]);
        }
    }
}

int main()
{
    int optn, val;
    char contn;

    printf("Stack operations:\n 1- PUSH.\n 2- POP.\n 3- Display stack.\n");

    do {
        printf("Enter option (1-4): ");
        scanf("%d", &optn);

        switch(optn)
        {
            case 1:
                PUSH(val);
                break;
            case 2:
                POP();
                break;
            case 3:
                display();
                break;
            default:
                printf("Incorrect option.\nPlease choose from given options.\n");
                break;
        }
        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c", &contn);
    }
    while(contn == 'Y' || contn == 'y');

    printf("\nProgram terminates successfully...\n\n");

    return 0;
}