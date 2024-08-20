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
            output_exp[output_index++] = ' '; // Add space to separate operators
            stack[++stack_index] = c;
        }
    }

    while (stack_index >= 0) {
        output_exp[output_index++] = stack[stack_index--];
        output_exp[output_index++] = ' '; // Add space to separate operators
    }

    output_exp[output_index] = '\0';
    printf("Postfix expression:\n %s\n", output_exp);

    // Evaluation of Postfix Expression
    int evaluation[MAX];
    int eval_index = -1;
    int i = 0;

    while (output_exp[i] != '\0') {
        if (isdigit(output_exp[i])) {
            int num = 0;
            // Collect the entire number
            while (isdigit(output_exp[i])) {
                num = num * 10 + (output_exp[i] - '0');
                i++;
            }
            evaluation[++eval_index] = num;
        } else if (output_exp[i] == ' ') {
            i++; // Move past the space
        } else if (output_exp[i] == '+' || output_exp[i] == '-' || output_exp[i] == '*' || output_exp[i] == '/') {
            int b = evaluation[eval_index--];
            int a = evaluation[eval_index--];
            int result = 0;

            if (output_exp[i] == '+') {
                result = a + b;
            } else if (output_exp[i] == '-') {
                result = a - b;
            } else if (output_exp[i] == '*') {
                result = a * b;
            } else if (output_exp[i] == '/') {
                result = a / b;
            }

            evaluation[++eval_index] = result;
            i++;
        } else {
            i++; // Move past any unexpected character
        }
    }

    printf("Evaluation of expression:\n %d\n", evaluation[eval_index]);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; // Remove trailing newline

    Postfix(exp);

    return 0;
}
