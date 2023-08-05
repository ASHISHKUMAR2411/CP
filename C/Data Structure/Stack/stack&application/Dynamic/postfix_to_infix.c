#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char **stack,*temp;
int top=-1;
char postfix[max];
int n,len;
char *pop(void);
void push(char *);
int main()
{
    int j=0;
    char symbol,dummy[3*max],sting1[3*max],last2[3*max];
    char *ptr,*ctr;
    gets(postfix);
    n=strlen(postfix);
    len=n*sizeof(char *)+3*n*sizeof(char);
    stack=(char **)malloc(len);
    temp=(char *)(stack + n);
    for(int i=0;i<n;i++)
    {
        stack[i]=(temp+3*n*i);
    }
    while(j<n)
    {
        symbol=postfix[j];
        switch (symbol)
        {
        case '*':
        case '/':
        case '^':
        case '+':
        case '-':
            ptr=pop();
            ctr=pop();
            dummy[0]='(';
            int k=1;
            while(*ptr!='\0')
            {
                dummy[k++]=*ptr;
                ptr++;
            }
            dummy[k++]=symbol;
            while(*ctr!='\0')
            {
                 dummy[k++]=*ctr;
                 ctr++;
            }
            dummy[k]='\0';
            push(dummy);
            break;
        
        default:push(&symbol);
            break;
        }

    }
    if(top==0)
    {
        puts(stack[top]);
    }
    else
    {
        printf("\n entered wrong");
    }
     return 0;

}
char *pop(void)
{
    char *poping=(char *)malloc(sizeof(char)*3*n);
    int j=0;
    if(top==-1)
    {
        printf("\n stack underflow");
        exit(0);
    }
    else
    {
        while(stack[top][j]!='\0')
        {
            *poping=stack[top][j]; 
            poping++;
             j++;
        }
        top -= 1;
        return poping;
    }

}
void push(char *p)
{
    p=(char *)malloc(3*n*sizeof(char));
    top+=1;
    int j=0;
    while(*p!='\0')
    {
        stack[top][j]=*p;
        p++;
        j++;
    }
}
