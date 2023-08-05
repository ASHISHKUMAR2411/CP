#include<stdio.h>
#include<stdlib.h>
void rotate(int *p,int n,int d);
int main()
{
    int n,a[20],d,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n times : ");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("\n number of roattion : ");
        scanf("%d",&d);
        rotate(a,n,d);
    }
    return 0;
}
void rotate(int *p,int n,int d)
{
    printf("\n");
    for(int i=d;i<d+n;i++)
    {
        printf("%d ",p[i%n]);
    }
}