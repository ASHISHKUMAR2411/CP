#include<stdio.h>
#include<string.h>
int main()
{
    char ch[25];
    int n ;
    printf("\n enter your name \t");
    gets(ch);
    for(int i=0;i<=strlen(ch);i++)
    {
        printf("\n%d\t",ch[i]);
    }
return 0;
}