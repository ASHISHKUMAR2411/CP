#include<stdio.h>
#include<string.h>
#include<string.h>
#include<limits.h>
int gcd(int d,int n);
int main()
{
    int n,a[20],min,k=0,temp, l,m=0,p=0,q=0,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        min=a[i];
        for(int j=i;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                k=j;
            }
        }
        l=gcd((k+1),n);
        for( m=i;m<l;m++)
        {
          temp=a[m];
          p=m;
          while(1)
          {
              q=p+(k+1);
              if(q>=n)
              q=q-n;
              if(q==m)
              break;
              a[p]=a[q];
              p=q;
          }
          a[p]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum+=i*a[i];
    }
    printf("\n sum is : %d",sum);
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