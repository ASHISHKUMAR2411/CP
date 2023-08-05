// dynamic allocation of the array 2D and manipulating
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,r,c,count=0;
    scanf("%d",&r);
    scanf("%d",&c);
    a=(int *)malloc(r*c*sizeof(int));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            *(a+i*c+j)=count++;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           printf("%3d ",*(a+i*c+j)); 
        }
        printf("\n");
    }
}