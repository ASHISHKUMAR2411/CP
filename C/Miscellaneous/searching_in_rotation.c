#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotate(int *p,int n,int d);
int gcd(int d,int n);
void search(int *p,int element,int n,int d);
int main()
{
    int n,a[20],d,element,s;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n how much you want to rotate : ");
    scanf("%d",&d);
    rotate(a,n,d);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n enter the element you ant to search : ");
    scanf("%d",&element);
    search(a,element,n,d);
    
    return 0;
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
void search(int *p,int element,int n,int d)
{
    int b=0,l=n-1,mid;
    if(p[b]>=element)
    {
        b=n-d;    
    }
    else
    {
        l=n-d-1;
    }
    while(b<=l)
    {
        
        mid=(b+l)/2;
        if(p[mid]==element)
        {
           printf("\n %d ",mid+1);
           break;
        }
        else if (p[mid]>element)
        {
            l=mid-1;
            
        }
        else
        {
            b=mid+1;
        }
        
    }
    
}