#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int A[50],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&*(A+i));
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(A+i));
    }
}