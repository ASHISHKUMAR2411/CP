// finding sum of 2D array using pointer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int m, n, A[15][15], (*q)[15], sum = 0;
    printf("\n enter the number of rows  in the matrix :");
    scanf("%d", &m);
    printf("\n enter the number of column  in the matrix :");
    scanf("%d", &n);
    for (int i = 0; i < m; i++)
    {
        printf("\n enter the %d row element :", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("\n enter the %d column element ", j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", A[i][j]);
        }
    }
    q = A;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = sum + *(*(A + i) + j);
        }
    }

    printf("\n the sum is %d", sum);
    return 0;
}