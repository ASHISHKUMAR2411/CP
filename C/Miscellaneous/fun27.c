#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    //printing every row and column with their average
    int m,n,i,j,A[15][15],sum1;
    printf("\n enter the extra row and column and fill any value at that positon of extra ");
    printf("\n enter the number of row ");
    scanf("%d",&m);
    printf("\n enter the number of column ");
    scanf("%d",&n);
    printf("\n enter the matrix elements when asked \t : ");
    printf("\n now enter the  matrix which will be asked from you \t");    
    for( i=0;i<=m;i++)
    {
        printf("\nenter the %d row elements ",i+1);
        for( j=0;j<=n;j++)
        {
            printf("\n enter the %d  column element of the %d row \t ",j+1,i+1);
            scanf("%d",&A[i][j]);
        }
    } 
    for( i=0;i<m;i++)
    {
        sum1=0;
        for( j=0;j<n;j++)
        {
            sum1+=A[i][j];
        }
        A[i][j]=sum1/n;
    } 
    for( i=0;i<n;i++)
    {
        sum1=0;
        for( j=0;j<m;j++)
        {
            sum1+=A[j][i];
        }
        A[j][i]=sum1/m;
    }
    for( i=0;i<=m;i++)
    {
        printf("\n");
        for( j=0;j<=n;j++)
        {
           printf("%d\t",A[i][j]);
        }
        
    }
    return 0;   
      

    
}