#include <stdio.h>
#include <string.h>

int precedence(char symbol);
int main()
{
    int t;
    char ch[1];
    scanf("%d", &t);
    gets(ch);
    while (t--)
    {
        char infix[401], temp, symbol;
        char dummy[400], postfix[400];
        int index = -1;
        int n, i = 0, position = 0;
        gets(infix);
        n = strlen(infix);
        while (i < n)
        {
            symbol = infix[i];
            switch (symbol)
            {
            case '(':
                if (index >= 400)
                    ;
                else
                {
                    index++;
                    dummy[index] = symbol;
                }
                break;
            case ')':
                if (index == -1)
                {
                    break;
                }
                else
                {
                    temp = dummy[index];
                    index--;
                }
                while (temp != '(')
                {
                    postfix[position++] = temp;
                    if (index == -1)
                    {
                        break;
                    }
                    else
                    {
                        temp = dummy[index];
                        index--;
                    }
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                while (precedence(dummy[index]) >= precedence(symbol))
                {
                    if (index == -1)
                    {
                        break;
                    }
                    else
                    {
                        temp = dummy[index];
                        index--;
                    }
                    if (temp == '(')
                    {
                        if (index >= 400)
                        {
                            break;
                        }
                        else
                        {
                            index++;
                            dummy[index] = temp;
                        }
                        break;
                    }
                    else
                    {
                        postfix[position++] = temp;
                    }
                }
                if (index >= 400)
                {
                    break;
                }
                else
                {
                    index++;
                    dummy[index] = symbol;
                }
                break;
            default:
                postfix[position++] = symbol;
                break;
            }
            i++;
        }
        while (index >= 0)
        {
            if (index == -1)
            {
                break;
            }
            else
            {
                temp = dummy[index];
                index--;
            }
            postfix[position++] = temp;
        }
        puts(postfix);
    }
    return 0;
}
int precedence(char symbol)
{
    if (symbol == '^')
    {
        return 5;
    }
    else if (symbol == '*')
    {
        return 4;
    }
    else if (symbol == '/')
    {
        return 3;
    }
    else if (symbol == '+')
    {
        return 2;
    }
    else if (symbol == '-')
    {
        return 1;
    }
    else
        return 0;
}