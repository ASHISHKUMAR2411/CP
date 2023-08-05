#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ch[20][50],ch1[1];
    int n,m;
    scanf("%d",&n);
    gets(ch1);
    char (*p)[20][50]=&ch;
    for(int i=0;i<n;i++)
    {
        gets((*p+i));
    }

    for(int i=0;i<n;i++)
    {
        puts((*p+i));
    }
}