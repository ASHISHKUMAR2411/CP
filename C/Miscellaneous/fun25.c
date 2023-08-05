#include<stdio.h>
void largest(int a[][15],int m, int n);
int main()
{
    // to find largest element in the matrix
    int m,n;
    int A[15][15];
    printf("\nenter the number of row you want in the matrix \t :");
    scanf("%d",&m);
    printf("\n enter the number of column you want in the matrix \t : ");
    scanf("%d",&n);
    printf("\n enter th ematrix elements when asked \t : ");
    for(int i=0;i<m;i++)
    {
        printf("\nenter the %d row elements ",i+1);
        for(int j=0;j<n;j++)
        {
            printf("\n enter the %d  column element of the %d row \t ",j+1,i+1);
            scanf("%d",&A[i][j]);
        }

    }
    for(int i=0;i<m;i++)
    { printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d \t",A[i][j]);
            
        }

    }
    
    largest(A,m,n);
    return 0;
}
void largest(int a[][15],int m, int n)
{
    int temp=0;
    for(int  i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n-1;k++)
            {
               if(a[i][k]>a[i][k+1])
               {
                    temp=a[i][k];
                    a[i][k]=a[i][k+1];
                    a[i][k+1]=temp;
               }
            }

        }

    }
    temp=0;
    for(int i=0;i<m-1;i++)
    {
        if(a[i][n-1]>a[i+1][n-1])
        {
            temp=a[i][n-1];
            a[i][n-1]=a[i+1][n-1];
            a[i+1][n-1]=temp;
        }
    }
    printf("\n the largest element in the matrix is  : %d",a[m-1][n-1]);

}