// done
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotation(int *p,int s,int e,int n);
int  gcd(int d,int n);
int main()
{
    int n,s,e,a[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter the range in which you want to rotate : ");
    scanf("%d %d",&s,&e);
    rotation(a,s,e,n);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void rotation(int *p,int s,int e,int n)
{
    e=e%n;
    s=s%n;
    if(e>s)
    {
        for(int i=s;i<e;i++)
        {
            int x=p[i];
            for(int j=s;j<=e-1;j++)
            {
                p[j]=p[j+1];
            }
            p[e]=x;
        }
    }
    else
    {
        for(int i=e;i<s;i++)
        {
            int x=p[i];
            for(int j=e;j<=s-1;j++)
            {
                p[j]=p[j+1];
            }
            p[s]=x;
        }
    }
}
int  gcd(int d,int n)
{
    if(n>d)
    {
        return gcd(n,d);
    }
    if(n==0)
    {
        return d;
    }
    else
    {
        return gcd(n,d%n);
    }
}