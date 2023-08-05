// using pointer to pointer we can create pointer
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r,c,count=0;
    scanf("%d",&r);
    scanf("%d",&c);
    int **a=(int **)calloc(r*sizeof(int *),c*sizeof(int));
    // for(int i=0;i<r;i++)
    // {
    //     a[i]=(int *)malloc(c*sizeof(int));
    // }
    if(a==NULL)
    {
        printf("memory not found");
    }
    else
    {
        // if(a[0]==NULL)
        // {
        //     printf("memory not found");
        // }
        // else
        // {
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
        // }
    }
    free(a);
    return 0;
}