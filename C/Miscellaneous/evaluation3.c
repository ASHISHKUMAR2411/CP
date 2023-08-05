#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int transpose(int *p[],int n );
int main()
{
    int M[5][5],i,j,n;
    printf("\n enter the dimension in the matrix\t");
    scanf("%d",&n);
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
    transpose(&M[0][0],n );
    return 0;
}
int transpose(int *p[5],int n )
{
    int *temp,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            temp=*(p[i]+j);
            *(p[i]+j)=*(p[j]+i);
            *(p[i]+j)=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",(*(p[i]+j)));
        }
        printf("\n");
    }
    return 0;
}
