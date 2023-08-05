// in this we will see the manipulation of the 2d array with array of pointer
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int A[10][20],m,n;
    int (*p)[20]=A;
    printf("\n enter the number of rows in the array : ");
    scanf("%d",&m);
    printf("\n enter the number of column in the array : ");
    scanf("%d",&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\n enter the %d %d  element ",i+1,j+1);
            scanf("%d",&(*(p+i))[j]);
        }
    }
    printf("\n now printing  the elements ");
    for(int i=0;i<m;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%5d",(*(p+i))[j]);
        }
    }

}