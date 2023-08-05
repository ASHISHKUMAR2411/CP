#include<stdio.h>
void multiply(int a[][15],int b[][15], int m, int n);
int main()
{
    // to multiply the two matrix of m*n and n*m matrix
    int m,n;
    int A[15][15],B[15][15];
    printf("\nremember one thing that row of one matrix is column of the other and vice versa ");
    printf("\ni.e one matrix is M*N  and the other is N*M ");
    printf("\nenter the number of row you want in the matrix1 \n which is going to be column of matrix 2 \t :");
    scanf("%d",&m);
    printf("\n enter the number of column you want in the matrix\n which be row of the second matrix  \t : ");
    scanf("%d",&n);
    printf("\n enter the matrix elements when asked \t : ");
    printf("\n now enter the first matrix which will be asked from you \t")
    for(int i=0;i<m;i++)
    {
        printf("\nenter the %d row elements ",i+1);
        for(int j=0;j<n;j++)
        {
            printf("\n enter the %d  column element of the %d row \t ",j+1,i+1);
            scanf("%d",&A[i][j]);
        }

    }
    printf("\n now enter the second matrix elements when asked in similar manner ");
    for(int i=0;i<m;i++)
    {
        printf("\nenter the %d row elements ",i+1);
        for(int j=0;j<n;j++)
        {
            printf("\n enter the %d  column element of the %d row \t ",j+1,i+1);
            scanf("%d",B[i][j]);
        }

    }
    printf("\n this is what you enter in the first matrix ");
    for(int i=0;i<m;i++)
    { printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d \t",A[i][j]);
            
        }

    }
    printf("\n this is what you enter in the second matrix ");
    for(int i=0;i<m;i++)
    { printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d \t",B[i][j]);
            
        }

    }
    multiply(A,B,m,n);
    return 0;
}
void multiply(int a[][15],int b[][15], int m, int n)
{
    int C[15][15];
    for(int i=0;i<m;i++)
    {

        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                C[i][j] += a[i][k]*b[k][j];
            }    
        }
    }
    printf("\n this is what you will get when you multiply ");
    for(int i=0;i<m;)
}    
    
