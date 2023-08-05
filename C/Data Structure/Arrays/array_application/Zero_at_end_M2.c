#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a[20],n,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            a[count++]=a[i];
        }
    }
    for(int i=count;i<n;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}