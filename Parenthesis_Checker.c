#include<stdio.h>
#include<string.h>

#define MAX 100

void parenthesis_check(char s[])
{
    char stack[MAX];
    int stack_index = -1;
    int len = strlen(s);
    char input[MAX];
    int input_index = -1;
    int flag = 0;

    for(int i = 0; i < len; i++)
    {
        char c = s[i];
        

        if(c == '(' || c == '[' || c == '{')
        {
            stack_index++;
            stack[stack_index]  = c;
        }
        else if(c == ')' || c == ']' || c == '}')
        {
            if(stack_index > -1)
            {
                if((c == ')' && stack[stack_index] == '(') || (c == ']' && stack[stack_index] == '[') || (c == '}' && stack[stack_index] == '{'))
                {
                    stack_index--;
                    // printf("%d \n", stack_index);
                }
                else
                {
                    // printf("Unbalanced!\n");
                    flag = 1;
    break;
                }
            }
            else if(stack_index == -1)
            {
                // printf("Unbalanced!\n");
                flag = 1;
    break;
            }
        }
    }

    if(stack_index == -1)
    {
        if(flag == 0)
        {
            printf("\nParenthesis string is balanced...\n\n");
        }
        else
        {
            printf("\nStirng is unbalanced...\n\n");
        }
    }
    else if(stack_index >= 0)
    {
        printf("\nString is unbalanced...\n\n");
    }
}

int main()
{
    char string[MAX];

    printf("Parenthesis Checker:\n\n");
    printf("Enter parenthesis string: ");
    fgets(string, MAX, stdin);
    // printf("String of parenthesis:\n %s", string);

    parenthesis_check(string);

    return 0;
}