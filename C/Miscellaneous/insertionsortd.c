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
    for(i=1;i<n;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0&&A[j]<temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}