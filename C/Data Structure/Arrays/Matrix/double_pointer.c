#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int A[10][10],*p[10],m,n,k=0;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         printf("%d ",**(*(p+i)+j));
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            p[k++]=&A[i][j];
        }
    }
    for(int k=k-1;k>=0;k--)
        {
            printf("%d ",*p[k]);
        }
    


    
    return 0;
}