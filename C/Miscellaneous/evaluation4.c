#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int multiplymat(int *p1[],int n,int *p2[] );
int main()
{
    int M[5][5],N[5][5],i,j,n;
    printf("\n enter the dimension in the 1st matrix\t");
    scanf("%d",&n); //we will have n*n matrix
    printf("\n enter the matrix rowwise when asked ");
    for ( i = 0; i <n ; i++)
    {   
        printf("\nthe %d row",i+1);
        for(j=0;j<n;j++)
        {
            printf("enter the %d column element",j+1);
            scanf("%d",&M[i][j]);
        }
    }
    //we will have 2nd matrix also n*n matrix so easy for multiply
    printf("\n enter the 2nd matrix rowwise when asked ");
    for ( i = 0; i <n ; i++)
    {   
        printf("\nthe %d row",i+1);
        for(j=0;j<n;j++)
        {
            printf("enter the %d column element",j+1);
            scanf("%d",&N[i][j]);
        }
    }
    multiplymat(&M[0][0],n,&N[0][0]);
    return 0;
}
int multiplymat(int *p1[],int n,int *p2[])
{
    int *c[5],i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            k=0;
            while(k<n)
            {
                *(*(c[i]+j))+=(*(*(p1[i]+k))) * (*(*(p2[k]+j)));
                k++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n,j++)
        {
            printf("%d",*(c[i]+j));
        }
        printf("\n");
    }

    return 0;
}