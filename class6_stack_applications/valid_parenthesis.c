#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
 
 bool isValid(char * s){


    int len=strlen(s);

    char stack[len];
    int top=-1;


    for (int i = 0; i < len; i++) 
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
            {
                stack[++top]=s[i];
                continue;
            }

            if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
            {
                if (top==-1)
                    return false;

                else if (s[i] == ')' && stack[top] == '(') 
                {
                    top--;
                } 
                
                else if (s[i] == '}' && stack[top] == '{') 
                {
                    top--;
                } 
                else if (s[i] == ']' && stack[top] == '[') 
                {
                    top--;
                } 
                
                else {
                    break;
                }
            }
        }

        if (top==-1)
            return true;

        return false;
}


int main() {
    char input[100];

    printf("Enter a string with brackets: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("The string has valid bracket configuration.\n");
    } else {
        printf("The string does not have valid bracket configuration.\n");
    }

    return 0;
}