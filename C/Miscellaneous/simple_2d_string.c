#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char A[50][50],ch[1];
    int n;
    scanf("%d",&n);
    gets(ch);
    for(int i=0;i<n;i++)
    {
        gets(A[i]);
    }
    for(int i=0;i<n;i++)
    {
        puts(A[i]);
    }
}