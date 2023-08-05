#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char A[50];
    int n;
    gets(A);
    n=strlen(A);
    for(int i=0;i<n;i++)
    {
        printf("%c ",*(A+i));
    }
}