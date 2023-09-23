#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define MAX 20

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;

    int i, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
            continue;
        }

        if (ch == '(') {
            stack[++top] = ch;
            continue;
        }

        if (ch == ')') {
            // Pop every element until you encounter an opening bracket in the stack.
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
            continue;
        }

        if (isOperator(ch)) {
            while (top > -1 && (precedence(ch) <= precedence(stack[top]))) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top > -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
