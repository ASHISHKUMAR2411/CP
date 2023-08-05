// using 2nd method for stack implemeting the postfix to infix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
struct stack
{
    int count ;
    char *stack[max];
}s;
void display();
void push(char *c);
char *pop();
int empty();
int operand(char c);
char *operator="+-*/^\0";
int getPrecedence(char c);
int oper(char c);
int getLowestPrecedenceMainOp(char *subexp);
char *concatCharP(char *start,char *middle,char *end);
void infix(char *expression);
char *readline();
int main()
{
    int test=1;
    if(test ==0)
    {
        printf("insert expression");
        char *expression=readline();
        infix(expression);
    }
    else
    {  
        char *expression[]={
            "AB-CDEF/+G-*-H",
            "ABC-CDEF/+G*-H*+",      
            "AB+C/",
            "ABC/+"};
        int sizeexp=sizeof(expression)/sizeof(expression[0]);
        for(int i=0;i<sizeexp;i++)
        {
            char *express=expression[i];
            printf("%d)\n",i+1);
            printf("postfix: %s\n",express);
            infix(express);
        }
    }
    return 0;
}
void display()
{
    if(s.count==0)
    {
        printf("\n the stack is empty");
    }
    else
    {
        printf("stack data is : ");
        for(int i=s.count-1;i>=0;i--)
        {
            printf("\n");
            printf("%s",s.stack[i]);
        }
    }
}
void push(char *c)
{
    if(s.count<max)
    {
        s.count=s.count+1;
        s.stack[s.count]=c;
    }
    else
    {
        printf("\n stack is full");
    }
}
char *pop()
{
    char *item;
    if(s.count>0)
    {
        item=s.stack[s.count];
        s.count=s.count-1;
    }
    return item;
}
int empty()
{
    return s.count==0;
}
int operand(char c)
{
    return (c>='A' && c<='Z');
}
int getPrecedence(char c)
{
    int result=0;
    for(int i=0;operator[i]!='\0';i++)
    {
        result++;
        if(operator[i]==c)
        {
            if(c=='-'||c=='/')
            {
                result--;
            }
            break;
        }
    }
}
int oper(char c)
{
    int result=0;
    for(int i=0;operator[i]!='\0';i++)
    {
        if(operator[i]==c)
        {
            result=1;
            break;
        }
    }
}
int getLowestPrecedenceMainOp(char *subexp)
{
    int lowest=100;
    int parentesis_count=0;
    for(int i=0;subexp[i]!='\0';i++)
    {
        char c=subexp[i];
        
        if(parentesis_count==0 && oper(c))
        {
            int operator_precedence=getPrecedence(c);
            if(operator_precedence<lowest)
            {
                lowest=operator_precedence;
            }
        }
        else if(c=='(')
        {
            parentesis_count++;
        }
        else if(c==')')
        {
            parentesis_count--;
        }
    }
    return lowest;
}
char *concatCharP(char *start,char *middle,char *end)
{
    char *result=(char *)malloc(sizeof(char));
    int idx=0;
    for(int i=0;start[i]!='\0';i++)
    result[idx++]=start[i];
    for(int i=0;middle[i]!='\0';i++)
    result[idx++]=middle[i];
    for(int i=0;end[i]!='\0';i++)
    result[idx++]=end[i];

    result[idx]='\0';
    return result;
}
void infix(char *expression)
{
    s.count = 0;
    char *ans;
    for(int i=0;expression[i]!='\0';i++)
    {
        char *cp=(char *)malloc(sizeof(char));
        cp[0]=expression[i];
        if(operand(cp[0]))
        {
            push(cp);
        }
        else
        {
            char *expre2 = pop();
            char *expre1 = pop();
            int operator_precedence=getPrecedence(cp[0]);
            int lowest_precedence_exp2=getLowestPrecedenceMainOp(expre2); 
            int lowest_precedence_exp1=getLowestPrecedenceMainOp(expre1);

            if(lowest_precedence_exp2<operator_precedence)
            {
                expre2=concatCharP("(",expre2,")");
            }
            if(lowest_precedence_exp1<operator_precedence)
            {
                expre1=concatCharP("(",expre1,")");
            }
            char *newexpression=concatCharP(expre1,cp,expre2);
            push(newexpression);
        }
    }
    ans=pop();
    printf("\n infix is : %s",ans);
}
char *readline()
{
    char *result=(char *)malloc(sizeof(char));
    int idx=0;
    char c;
    while((c=getchar()) !='\n' && c!= EOF)
    {
        result[idx++]=c;
    }
    result[idx]='\0';
    return result;
}