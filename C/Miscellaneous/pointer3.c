#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // understanding the pointer accessisibility
    // array itself is a  pointer 
    int A[10][10], *p, **q, m, n, B[10], (**r)[10];
    printf("\n enter the number of rows you want in the array ");
    scanf("%d", &m);
    printf("\n enter the number of column you want ");
    scanf("%d", &n);
    printf("\n enter the element of matrix");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n enter the %d row  %d column element  : ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n now enter the next  array for testing single dimension array ");
    for (int i = 0; i < n; i++)
    {
        printf("\n enter the element of the matrix : ");
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ",A[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",B[i]);
    }
    p = B;
    r=A;
    // q =(int **)A;
    printf("\n%d", p);
    printf("\n%d", *p);
    printf("\n%d", *(p + 2));
    p++;

    printf("\n%d",*p);
    printf("\n%d", *p++);
    printf("\n%d", *p);
    printf("\n%d", *p++);
    ++p;
    printf("\n%d", *p);
    printf("\n%d", ++*p);
    printf("\n%d", *p);
    printf("\n%d", p);
    printf("\n%d", *(p - 1));
    printf("\n%d", *++p);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",B[i]);
    }

    printf("\n now for the matrix");
    printf("\n%d",**A); 
    printf("\n%d",**(A+1));
    printf("\n%d",**A+1);
    printf("\n%d",*(*A+1));
    printf("\n%d",++**A);
    printf("\n%d",(**A)++);
    printf("\n%d",++(**A));
    printf("\n%d",*(*(A+3)+4));
    printf("\n%d",**(A+2));
    printf("\n now for the matrix");
    printf("\n%d",**r); 
    printf("\n%d",**(r+1));
    printf("\n%d",**r+1);
    printf("\n%d",*(*r+1));
    // printf("\n%d",++**r);
    // printf("\n%d",(**r)++);
    // printf("\n%d",++(**r));
    printf("\n%d",*(*(r+3)+4));
    printf("\n%d",**(r+2));

    // printf("\n now for the matrix");
    // printf("\n%d",**q); 
    // printf("\n%d",**(q+1));
    // printf("\n%d",**q+1);
    // printf("\n%d",*(*q+1));
    // printf("\n%d",++**q);
    // printf("\n%d",(**q)++);
    // printf("\n%d",++(**q));
    // printf("\n%d",*(*(q+3)+4));
    // printf("\n%d",**(q+2));
    return 0;
}