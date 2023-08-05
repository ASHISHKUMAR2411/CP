#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ch[20];
    int n;
    char (*c)[20]=&ch;
    gets(*c);
    n=strlen(*c);
    for(int i=0;i<n;i++)
    {
        printf("%c",*(*c+i));
    }
}