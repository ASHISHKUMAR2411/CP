#include<stdio.h>
#include<string.h>
int main()
{
    // sorting 2D matrix column wise i.e each column will be sorted 
    int m,n,A[15][15],temp=0;
    printf("\nenter the number of row in the matrix \t : ");
    scanf("%d",&m);
    printf("\n enter the number of column in the matrix \t : ");
    scanf("%d",&n);
    printf("\n enter the element of the matrix when asked ");
    for(int i=0;i<m;i++)
    {
        printf("\n enter the element of the %d row at asked column ",i+1);
        for(int j=0;j<n;j++)
        {
            printf("\n enter the %d column element : \t ",j+1);
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<m;k++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(A[j][i]>A[j+1][i])
                {
                    temp=A[j][i];
                    A[j][i]=A[j+1][i];
                    A[j+1][i]=temp;
                }
            }
        }
    }
    printf("\n the matrix now look like \n");
    for(int i=0;i<m;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d  ",A[i][j]);
        }
    }

}