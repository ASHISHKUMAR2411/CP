#include<stdio.h>
#include<string.h>
int main()
{
    // insertion sort in 2D 
    int i=0,j=0,k=0,l=1,temp=0,A[15][15],m,n;
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


