#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int A[20],i,j,n,temp=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&j);
    for(int i=0;i<n;i++)
    {
        if(A[i]==j)
        {
            printf("%d",i+1);
        }
        else
        {
            printf("NIL");
        }
    }
    return 0;
}