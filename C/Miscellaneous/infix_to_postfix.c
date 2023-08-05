#include<stdio.h>
#include<string.h>
#include<string.h>
char stack[100],postfix[100];
int top=-1;
int pre(char symbol);
char pop(void);
void push(char symbol);

int main()
{
    char infix[50],temp,symbol;
    int n,i=0,position=0;;
    printf("\n enter the expression : ");
    gets(infix);
    n=strlen(infix);
    while(i<n)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(' : push(symbol);
            break;
            case ')':  temp=pop();
            while(temp != '(')
            {
                postfix[position++]=temp;
                temp = pop() ;
            }
            break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            while(pre(stack[top])>=pre(symbol) )
            {
                temp=pop();
                if(temp=='(')
                {
                    push(temp);
                    break;
                }
                else
                {
                    postfix[position++]=temp;
                }
                
            }
            push(symbol);
            break;
            default : postfix[position++]=symbol;
            break;
        }
        i++;
    }
    while(top>=0)
    {
        temp=pop();
        postfix[position++]=temp;
    }
    puts(postfix);
    return 0;
}
int pre(char symbol)
{
    if(symbol=='^')
    {
        return 5;
    }
    else if(symbol=='*')
    {
        return 4;
    }
    else if(symbol=='/')
    {
        return 3;
    }
    else if(symbol=='+')
    {
        return 2;
    }
    else if(symbol=='-')
    {
        return 1;
    }
    else 
    return 0;
    
    
}
char pop(void)
{
    char temp;
    if(top==-1)
    {
        printf("\n stack overflow");
        return '0';
    }
    else
    {
        temp=stack[top];
        top--;
    }
    return temp;
}
void push(char symbol)
{
    if(top>=99)
    {
        printf("\n stack overflow");
    }
    else
    {
        top++;
        stack[top]=symbol;
    }

}