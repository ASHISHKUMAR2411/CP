#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int A[50][10],n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        scanf("%d",&*(*(A+i)+j));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        printf("%d ",*(*(A+i)+j));
        printf("\n");
    }
}