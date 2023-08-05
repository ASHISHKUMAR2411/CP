#include<stdio.h>
int main()
{
    int A[10][10],m,n;
    int *p;
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }
    p=A;
    printf("\n%d",*p);
    printf("\n%d",p);
    printf("\n%d",*p++);
    printf("\n%d",p);
    printf("\n%d",*p++);
    printf("\n%d",p);
    printf("\n%d",*p++);
    printf("\n%d",p);
}