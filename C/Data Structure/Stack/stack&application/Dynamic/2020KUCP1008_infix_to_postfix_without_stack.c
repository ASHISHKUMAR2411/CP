#include<stdio.h>
#include<string.h>
#include<string.h>
char dummy[100],postfix[100];
int index=-1;
int precedence(char symbol);
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
            case '(' :
                if(index>=99)
                {
                    printf("\n no more elemnet to store");
                }
                else
                {
                    index++;
                    dummy[index]=symbol;
                }
            break;
            case ')':  
                if(index==-1)
                {
                    printf("\n no element found ");
                    break;
                }
                else
                {
                    temp=dummy[index];
                    index--;
                }
                while(temp != '(')
                {
                    postfix[position++]=temp;
                    if(index==-1)
                    {
                        printf("\n no element found ");
                        break;
                    }
                    else
                    {
                        temp=dummy[index];
                        index--;
                    }
                }
            break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                while(precedence(dummy[index])>=precedence(symbol) )
                {
                    if(index==-1)
                    {
                        printf("\n no element found ");
                        break;
                    }
                    else
                    {
                        temp=dummy[index];
                        index--;
                    }
                    if(temp=='(')
                    {
                        if(index>=99)
                        {
                            printf("\n no more element  stored ");
                            break;
                        }
                        else
                        {
                            index++;
                            dummy[index]=temp;
                        }
                        break;
                        
                    }
                    else
                    {
                        postfix[position++]=temp;
                    }
                
                }
                if(index>=99)
                {
                    printf("\n no more elements  stored ");
                    break;
                }
                else
                {
                    index++;
                    dummy[index]=symbol;
                }
            break;
            default : postfix[position++]=symbol;
            break;
        }
        i++;
    }
    while(index>=0)
    {
        if(index==-1)
        {
            printf("\n no elements found ");
            break;
        }
        else
        {
            temp=dummy[index];
            index--;
        }
        postfix[position++]=temp;
    }
    puts(postfix);
    return 0;
}
int precedence(char symbol)
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
