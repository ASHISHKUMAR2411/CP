#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    char ch[34];
    printf("\n enter the string you want to print \t ");
    gets(ch);
    n=strlen(ch);
    for(int i=0;i<=n;i++)
    {
        printf("\n %.*s",i,ch);
    }
    for(int i=n;i>=0;i--)
    {
        printf("\n %.*s",i,ch);
    }
    return 0;
}