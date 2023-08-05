//  time complexoty is O(n^2)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotate(int *p,int n,int d);
int gcd(int d,int n);
void sort(int *A,int n);
void serachsum(int *p,int n,int m);
int main()
{
    int n,d,a[20],m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n enter the number of rotation you want  ");
    scanf("%d",&d);
    rotate(a,n,d);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n enter the sum : ");
    scanf("%d",&m);
    serachsum(a,n,m);
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
void serachsum(int *p,int n,int m)
{
    int sum;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            sum=p[i]+p[j+1];
            if(sum==m)
            {
                printf("\nYes \n the pair(%d,%d) makes %d ",p[i],p[j+1],m);
                exit(0);
            }
        }
    }
    printf("\nNO");
}