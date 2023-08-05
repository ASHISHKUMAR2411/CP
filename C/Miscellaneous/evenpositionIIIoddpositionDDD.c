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
    for(j=2;j<n;j++)
    {
        temp=A[j];
        i=j-1;
        while(i>=0&&A[i]>temp)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}