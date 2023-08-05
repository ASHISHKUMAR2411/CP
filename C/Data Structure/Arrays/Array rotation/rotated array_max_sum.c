#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotate(int *p,int n,int d);
int gcd(int d,int n);
int main()
{
    int n,a[20],sum=0,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum+=a[j]*j;
        }
        if(sum>max)
        {
            max=sum;
        }
        rotate(a,n,1);
    }
    printf("\n sum id : %d",max);
}
void rotate(int *p,int n,int d)
{
    d=d%n;
    int temp,k=0,j=0, l;
    l=gcd(d,n);
    for(int i=0;i<l;i++)
    {
          temp=p[i];
          j=i;
          while(1)
          {
              k=j+d;
              if(k>=n)
              k=k-n;
              if(k==i)
              break;
              p[j]=p[k];
              j=k;
          }
          p[j]=temp;
    }
}
int gcd(int d,int n)
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