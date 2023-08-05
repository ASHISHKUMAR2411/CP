    /* ASHISH KUMAR
    2020KUCP1008

    Que) implementing postfix to prefix using stack and informing about stack used in the program 


    No of Stack used  - 1
    
    */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// *Here we are initialising the MAXIMUM Size of the stack and string
// we are implementing without parenthesis

#define MAX 20

// Initialising stack
char postfix[MAX], stack[MAX];
int topIndex = -1;

void push(char symbol);
char pop();
int checkIfOperand(char symbol);
int isOperator(char symbol);
void postfixToPrefix();

// main starts
int main()
{
    postfixToPrefix();

    return 0;
}
// main ends

void push(char symbol)
{
    // we are adding element in stack in the top
    stack[++topIndex] = symbol;
}

char pop()
{
    // pop is popping out an element from the stack
    return stack[topIndex--];
}
int checkIfOperand(char symbol)
{
    // it check the operand and return 1 or 0 accordingly 
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

int isOperator(char symbol)
{
    // it checks whether their is operator or not 
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
    // here postfix to prefix function starts 
    int n, i, j = 0;
    char dummy1[20];
    char a, b, op;

    printf("Enter the postfix expression\n");
    scanf("%s", postfix);

    n = strlen(postfix);

    printf("Prefix expression is:\t");
    for (i = n - 1; i >= 0; i--)
    {
        if (isOperator(postfix[i]))
        {
            push(postfix[i]);
        }
        else
        {
            dummy1[j++] = postfix[i];
            while ((topIndex != -1) && (stack[topIndex] == '#'))
            {
                a = pop();
                dummy1[j++] = pop();
            }
            push('#');
        }
    }
    dummy1[j] = '\0';

    i = 0;
    j = strlen(dummy1) - 1;
    char dummy2[20];

    while (dummy1[i] != '\0')
    {
        dummy2[j--] = dummy1[i++];
    }

    printf("%s\n", dummy2);
}