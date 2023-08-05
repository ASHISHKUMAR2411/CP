#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
int main()
{
    int a[20][20];
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int (*p)[20][20]=&a;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d ", *(*(*p+i)+j));
        }
    }
    return 0;
}