#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <stdbool.h>

#define MAX 20

char str[MAX], stack[MAX];
int index= -1;

void push(char expression);
char pop();
int checkIfOperand(char symbol);
int checkIfOperator(char symbol);
void postfixToPrefix();
int main()
{
    postfixToPrefix();
    return 0;
}
void push(char expression)
{
    stack[++index] = expression;
}

char pop()
{
    return stack[index--];
}
// A utility function to check if the given character is operand
int checkIfOperand(char symbol)
{
    return ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'));
}

//function to check if it is an operator
int checkIfOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return 1;
    }
    return 0;
}

void postfixToPrefix()
{
    int n, i, j = 0;
    char c[20];
    char a, b, op;

    printf("Enter the postfix expression\n");
    scanf("%s", str);

    n = strlen(str);

    for (i = 0; i < MAX; i++)
        stack[i] = '\0';
    printf("Prefix expression is:\t");

    for (i = n - 1; i >= 0; i--)
    {
        if (checkIfOperator(str[i]))
        {
            push(str[i]);
        }
        else
        {
            c[j++] = str[i];
            while ((index != -1))
            {
                a = pop();
                c[j++] = pop();
            }
            push('#');
        }
    }
    c[j] = '\0';

    i = 0;
    j = strlen(c) - 1;
    char d[20];

    while (c[i] != '\0')
    {
        d[j--] = c[i++];
    }
    printf("%s\n", d);
}