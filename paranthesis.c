#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

bool isvalid(char *s)
{
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        // Handle closing brackets
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Stack empty → invalid
            if (top == -1)
                return false;

            char topchar = stack[top--]; // Pop top element

            // Check for mismatch
            if ((ch == ')' && topchar != '(') ||
                (ch == '}' && topchar != '{') ||
                (ch == ']' && topchar != '['))
            {
                return false;
            }
        }
    }

    // If stack empty, valid
    if (top == -1)
        return true;
    else
        return false;
}

int main()
{
    char s[100];
    printf("Enter the string brackets: ");
    scanf("%s", s);

    if (isvalid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
