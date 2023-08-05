#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char expression[50];
    printf("\n enter the postfix expression : ");
    gets(expression);
    infix(expression);
    return 0;
}
void infix(char *expression)
{
    char *cp;
    for(int i=0;expression[i]!='\0';i++)
    {
        cp=(char *)malloc(sizeof(char));
        cp[0]=expression[i];
        if(opreand(cp[0]))
        {
            push(cp[0]);
        }
    }

}