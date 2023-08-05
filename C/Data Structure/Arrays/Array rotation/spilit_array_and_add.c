#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void split(int *p,int d,int n);
int main()
{
    int n,a[10],d;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter how much part you want to split and add");
    scanf("%d",&d);
    split(a,d,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void split(int *p,int d,int n)
{
    if(d<0)
    {
        return ;
    }
    int i=0;
    d=d%n;
    int temp[10];
    for(int i=0;i<d;i++)
    {
          temp[i]=p[i];
    }
    for(i=0;i<n-d;i++)
    {
         p[i]=p[i+d];
    }
    for(int j=0;j<d;j++)
    {
        p[i++]=temp[j];
    }
}