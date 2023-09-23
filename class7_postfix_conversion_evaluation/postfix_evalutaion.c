#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int evaluatePostfix(char *postfix) {
    int stack[MAX];
    int top = -1;

    int i, j = 0;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0';
            continue;
        }

        int op1 = stack[top--];
        int op2 = stack[top--];
        int res;

        switch (ch) {
            case '+':
                res = op2 + op1;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '*':
                res = op2 * op1;
                break;
            case '/':
                res = op2 / op1;
                break;
            default:
                break;
        }

        stack[++top] = res;
    }

    return stack[top];
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
