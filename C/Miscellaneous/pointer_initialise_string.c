#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ch[30];
    int n;
    gets(ch);
    n=strlen(ch);
    char *c=ch;
    for(int i=0;i<n;i++)
    {
        printf("%c",*(c+i));
    }
    return 0;
}