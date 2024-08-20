#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void Postfix(char s[]) {
    char output_exp[MAX];
    int output_index = 0;
    int len = strlen(s);
    char stack[MAX];
    int stack_index = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            output_exp[output_index++] = c;
        }
        else if (c == '(') {
            stack[++stack_index] = c;
        }
        else if (c == ')') {
            while (stack_index >= 0 && stack[stack_index] != '(') {
                output_exp[output_index++] = stack[stack_index--];
            }
            stack_index--;
        }
        else {
            while (stack_index >= 0 && (precedence(s[i]) < precedence(stack[stack_index]) ||
                                       precedence(s[i]) == precedence(stack[stack_index]))) {
                output_exp[output_index++] = stack[stack_index--];
            }
            stack[++stack_index] = c;
        }
    }

    while (stack_index >= 0) {
        output_exp[output_index++] = stack[stack_index--];
    }

    output_exp[output_index] = '\0';
    printf("Postfix expression:\n");
    printf(" %s\n", output_exp);

    int evaluation[MAX];
    int eval_index = -1;

    for(int i = 0; i < len;i++)
    {
        char e = output_exp[i];

        if((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
        {
            printf("Cannot evaluate character operands.\n");
        }
        else if(e >= '0' && e <= '9')
        {
            evaluation[eval_index++] = output_exp[output_index];
            output_index--;
        }
        else if((e == '+' || e == '-' || e == '*' || e == '/'))
        {
            int b = evaluation[eval_index];
            eval_index--;
            int a = evaluation[eval_index];
            eval_index--;
            if(e == '+')
            {
                int result = a + b;
                printf("%d + %d = %d\n", a, b, result);
                evaluation[eval_index++] = result;
            }
            else if(e == '-')
            {
                int result = a - b;
                printf("%d - %d = %d\n", a, b, result);
                evaluation[eval_index++] = result;
            }
            else if(e == '*')
            {
                int result = a * b;
                printf("%d * %d = %d\n", a, b, result);
                evaluation[eval_index++] = result;
            }
            else if(e == '/')
            {
                int result = a / b;
                printf("%d / %d = %d\n", a, b, result);
                evaluation[eval_index++] = result;
            }
        }
    }
    printf("Evaluation of expression:\n %d", evaluation[eval_index]);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    fgets(exp, MAX, stdin);
    printf("Expression:\n %s", exp);

    Postfix(exp);

    return 0;
}
