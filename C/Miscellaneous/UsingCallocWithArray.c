#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a[10],r,c,count=0;
    scanf("%d",&r);
    scanf("%d",&c);
    *a=(int *)calloc(r,c*sizeof(int));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=count++;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
    return 0;
}    