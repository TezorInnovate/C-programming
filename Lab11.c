#include<stdio.h>

#define MAX 100
int T1[MAX];
int T2[MAX];
int T3[MAX];
int top1 = -1;
int top2 = -1;
int top3 = -1;


void TOH(int n, int S[MAX], int D[MAX], int A[MAX])
{
    if(n == 1)
    {
        S[top] = D[];
    }
    else
    {
        return TOH(n-1, S, A, D);
        //move from  S to D
        return TOH(n-1, A, D, S);
    }
}
void source_creation(int n, int s)
{
    printf("Enter source tower(1-3): ");
    scanf("%d", &s);
    switch(s)
    {
        case 1:
            for(int i = 0; i < n; i++)
            {
                T1[++top1] = (n-i);
            }
            if(top1 == -1)
            {
                printf("Tower is empty.\n");
            }
            else
            {
                printf("Tower %d:\n", s);
                for(int i = top1; i >= 0; i--)
                {
                    printf("    %d\n", T1[i]);
                }
            }
            break;
        case 2:
            for(int i = 0; i < n; i++)
            {
                T2[++top2] = (n-i);
            }
            if(top2 == -1)
            {
                printf("Tower is empty.\n");
            }
            else
            {
                printf("Tower %d:\n", s);
                for(int i = top2; i >= 0; i--)
                {
                    printf("    %d\n", T2[i]);
                }
            }
            break;
        case 3:
            for(int i = 0; i < n; i++)
            {
                T3[++top3] = (n-i);
            }
            if(top3 == -1)
            {
                printf("Tower is empty.\n");
            }
            else
            {
                printf("Tower %d:\n", s);
                for(int i = top3; i >= 0; i--)
                {
                    printf("    %d\n", T3[i]);
                }
            }
            break;
        default:
            printf("Incorrect tower.\nChoose from given towers(1-3).\n");
            break;
    }
}

int main()
{
    int n, s;

    printf("Enter number of rings: ");
    scanf("%d", &n);
    source_creation(n, s);

    return 0;
}