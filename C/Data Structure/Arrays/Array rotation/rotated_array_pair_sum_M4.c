// M4 as using remainder of the lement less than x
// not evaluated as wanted . need improvement 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max 10000
void rotate(int *p,int n,int d,int m);
int gcd(int d,int n);
void sort(int *A,int n);
void pairsum(int *p,int n);
int main()
{
    int n,d,a[20],m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    // sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    // printf("\n enter the number of rotation you want  ");
    // scanf("%d",&d);
    // rotate(a,n,d);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",a[i]);
    // }
    // printf("\n enter the sum : ");
    // scanf("%d",&m);
    pairsum(a,n);
    return 0;
}
void rotate(int *p,int n,int d,int m)
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
void pairsum(int *p,int n)
{
    int min,j=0,sum=0;
    min=p[0];
    for(int k=0;k<n;k++)
    { 
        min=p[k];
        for(int i=k;i<n;i++)
        {
             if(p[i]<min)
             {
                 min=p[i];
                 j=i;
             }
        }
        rotate(&p[k],n-k,j,k);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    for(int i=0;i<n;i++)
    {
        sum += p[i]*i;
    }
    printf("sum is : %d",sum);
}