#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int A[20], B[20], C[30], i, j = 0, n;
    printf("\n enter the value of n : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        C[k] = A[i] + B[i] + j;
        switch (C[k])
        {
        case 0:
            C[k] = 0;
            j = 0;
            break;
        case 1:
            C[k] = 1;
            j = 0;
            break;
        case 2:
            C[k] = 0;
            j = 1;
            break;
        case 3:
            C[k] = 1;
            j = 1;
            break;
        default:
            printf("\n not valid number in binary is given in input ");
            exit (0);
            break;
        }
        k++;
    }
    C[k]=j;
    for (i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", B[i]);
    }
    printf("\n");
    for (i = k; i >=0; i--)
    {
        printf("%d", C[i]);
    }

    return 0;
}