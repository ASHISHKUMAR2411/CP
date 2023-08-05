// reverse swaping
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *p,int n);
int main()
{
    int n,a[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    swap(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void swap(int *p,int n)
{
    int temp,i;
    temp=p[n-1];
    for( i=n-1;i>0;i--)
    {
        p[i]=p[i-1];
    }
    p[0]=temp;
}