#include<stdio.h>
#include<string.h>
int main()
{
    // sorting 2D matrix row wise i.e each row will be sorted 
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
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(A[i][j]>A[i][j+1])
                {
                    temp=A[i][j];
                    A[i][j]=A[i][j+1];
                    A[i][j+1]=temp;
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