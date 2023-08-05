#include<stdio.h>
#include<string.h>
int main()
{
    // sorting all the elements rowise in 2D matrix 
    // using method comparing the last column element with the next row first element
    
    int i=0,j=0,k=0,l=0,temp=0,A[15][15],m,n;
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
            scanf("%d ",&A[i][j]);

        }
    } 
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d\t",A[i][j]);
        }
    }
    for(k=0;k<(m*n);k++)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(A[i][j]>A[i][j+1])
                {
                    temp=A[i][j];
                    A[i][j]=A[i][j+1];
                    A[i][j+1]=temp;
                }
            }
        }
        for(i=0;i<m-1;i++)    
        {
            if(A[i][n-1]>A[i+1][0])
            {
              temp=A[i][n-1];
              A[i][n-1]=A[i+1][0];
              A[i+1][0]=temp;
            }
        }
    }
    printf("\n the new matrix is \n");
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d\t",A[i][j]);
        }
    }
    return 0;
     
}