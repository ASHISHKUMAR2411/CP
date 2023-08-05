#include<stdio.h>
#include<string.h>
int main()
{
    //  Method 1 sorting 2D matrix ascending order of the whole matrix and representing in row form
    // converting 2D to 1D and sort then 1D to 2D 
    int m,n,A[15][15],temp=0,B[300],l=0;
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
            B[l++]=A[i][j];

        }
    }
    printf("\n the matrix given by you is \n");
    for(int i=0;i<m;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d  ",A[i][j]);
        }
    }
    for(int i=0;i<l-1;i++)
    {
        for(int j=0;j<l-1;j++)
        {
            if(B[j]>B[j+1])
            {
                temp=B[j];
                B[j]=B[j+1];
                B[j+1]=temp;
            }
        }
    }
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=B[k++];
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