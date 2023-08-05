/*  C Program to convert prefix to postfix using stack */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SPACE ' '
#define TAB '\t'
#define MAX 50

char *pop();
char prefix[MAX];
char stack[MAX][MAX];
void push(char *subExpression);
int isStackEmpty();
int checkWhiteSpaces(char symbol);
void prefixToPostfix();
int index;

int main()
{
    index = -1;
    printf("Enter Prefix Expression : ");
    gets(prefix);
    prefixToPostfix();

} /*End of main()*/

void prefixToPostfix()
{
    int i;
    char operand1[MAX], operand2[MAX];
    char symbol;
    char temp[2];
    char strin[MAX];
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        symbol = prefix[i];
        temp[0] = symbol;
        temp[1] = '\0';

        if (!checkWhiteSpaces(symbol))
        {
            switch (symbol)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                strcpy(operand1, pop());
                strcpy(operand2, pop());
                strcpy(strin, operand1);
                strcat(strin, operand2);
                strcat(strin, temp);
                push(strin);
                break;
            default: /*if an operand comes*/
                push(temp);
            }
        }
    }
    printf("\nPostfix Expression :: ");
    puts(stack[0]);
} /*End of prefixToPostfix()*/

void push(char *subExpression)
{
    if (index > MAX)
    {
        printf("\nStack overflow\n");
        exit(1);
    }
    else
    {
        index = index + 1;
        strcpy(stack[index], subExpression);
    }
} /*End of push()*/

char *pop()
{
    if (index == -1)
    {
        printf("\nStack underflow \n");
        exit(2);
    }
    else
        return (stack[index--]);
} /*End of pop()*/
int isStackEmpty()
{
    if (index == -1)
        return 1;
    else
        return 0;
}
int checkWhiteSpaces(char symbol)
{
    if (symbol == SPACE || symbol == TAB || symbol == '\0')
        return 1;
    else
        return 0;
} /*End of checkWhiteSpaces()*/