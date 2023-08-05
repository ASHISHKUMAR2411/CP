//  this is for counting the number of rotation a sorted array has
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void rotate(int *p,int n,int d);
int gcd(int d,int n);
void count(int *p,int n);
void sort(int *A,int n);
int main()
{
    int n,d,a[20],m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    printf("\n enter the rotated array : ");
    scanf("%d",&d);
    rotate(a,n,d);
    count(a,n);
    return 0;
}
void rotate(int *p,int n,int d)
{
    d=d%n;
    int temp,k=0,j=0, l;
    l=gcd(d,n);
    for(int i=k;i<l;i++)
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
void count(int *p,int n)
{
    int count =0,j=0;
    for(int i=1;i<n-1;i++)
    {
        if(p[i]<p[i-1])
        {
            count = n-i;
            break;
        }
    }
    printf("\n%d ",n-count);
}
void sort(int *A,int n)
{
    int temp,j=0;
    for(int i=1;i<n;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0&&A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}