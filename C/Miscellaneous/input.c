#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int input(char *s,int n);
int main()
{
    char str[100],ch[1];
    int m;
    scanf("%d",&m);
    gets(ch);
    int n=input(str,m);
    printf("%d %s",n,str);
    return 0;
}
int input(char *s,int n)
{
    int ch,i=0;
    while((ch=getchar())!='\n')
    {
        if(i<n)
        {
            s[i++]=ch;
        }
    }
    s[i]='\0';
    return i;
}