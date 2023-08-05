#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
int main()
{
    int a[20][20],n,m;
    int (*p)[20][20]=&a;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",(*(*p+i)+j));
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",*(*(*p+i)+j));

        }

    }
}