#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void ReverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void Prefix(char s[]) {
    char exp[MAX];
    int len = strlen(s);
    char stack[MAX];
    int stack_index = -1;
    int output_index = 0;

    ReverseString(s);

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (isdigit(c) || isalpha(c)) {
            exp[output_index++] = c;
        } else if (c == ')') {
            stack[++stack_index] = c;
        } else if (c == '(') {
            while (stack_index >= 0 && stack[stack_index] != ')') {
                exp[output_index++] = stack[stack_index--];
            }
            stack_index--;
        } else {
            while (stack_index >= 0 && precedence(c) <= precedence(stack[stack_index])) {
                exp[output_index++] = stack[stack_index--];
            }
            stack[++stack_index] = c;
        }
    }

    while (stack_index >= 0) {
        exp[output_index++] = stack[stack_index--];
    }

    exp[output_index] = '\0';

    ReverseString(exp);

    printf("Prefix expression:\n %s\n", exp);
    
    int evaluation[MAX];
    int eval_index = -1;
    
    for (int i = strlen(exp) - 1; i >= 0; i--) {
        char e = exp[i];

        if (isdigit(e)) {
            evaluation[++eval_index] = e - '0';
        } else if (e == '+' || e == '-' || e == '*' || e == '/') {
            int a = evaluation[eval_index--];
            int b = evaluation[eval_index--];
            int result = 0;

            if (e == '+') {
                result = a + b;
                printf("%d + %d = %d\n", a, b, result);
            } else if (e == '-') {
                result = a - b;
                printf("%d - %d = %d\n", a, b, result);
            } else if (e == '*') {
                result = a * b;
                printf("%d * %d = %d\n", a, b, result);
            } else if (e == '/') {
                result = a / b;
                printf("%d / %d = %d\n", a, b, result);
            }

            evaluation[++eval_index] = result;
        }
    }

    printf("Evaluation of prefix expression:\n %d\n", evaluation[eval_index]);
}

int main() {
    char exp[MAX];
    char contn;

    do {
        printf("Enter expression: ");
        fgets(exp, MAX, stdin);
        exp[strcspn(exp, "\n")] = '\0';

        Prefix(exp);

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &contn);

        while ((ch = getchar()) != '\n' && ch != EOF);

    }
    while(contn == 'y' || contn == 'Y');
    
    printf("\nProgram terminated successfully...\n\n");

    return 0;
}
