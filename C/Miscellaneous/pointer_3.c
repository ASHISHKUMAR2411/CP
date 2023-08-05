#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *mid(int *p,int n);
int main()
{
    int n,a[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *q , *p=a ;
    q=mid(p,n);
    printf("%d",*q);
    return 0;
}
int *mid(int *p,int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    *p=p[n/2];
    return p;
}