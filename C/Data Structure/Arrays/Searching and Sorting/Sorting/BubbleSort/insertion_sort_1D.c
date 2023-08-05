#include<stdio.h>
#include<string.h>
int main()
{
    // Insertion sort for 1D matrix
    int m,A[30],temp=0,j=0;
    printf("\nenter the number of row in the matrix \t : ");
    scanf("%d",&m);
    printf("\n enter the element of the matrix when asked ");
    for(int i=0;i<m;i++)
    {
        printf("\n enter the %d element  ",i+1);
        scanf("%d",&A[i]);
    }
    for(int i=1;i<m;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0&&A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
    printf("\n the new matrix is \n");
    for(int i=0;i<m;i++)
    {
        printf("%d\t",A[i]);
    }
    return 0;
}    
