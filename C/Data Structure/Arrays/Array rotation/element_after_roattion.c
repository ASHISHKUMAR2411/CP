// this is for finding the element after the roatation at the particular index .
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotate(int *p,int n,int d);
int gcd(int d,int n);
void minimum(int *p,int n,int d);
void MINIMUM(int *p,int n);
void sort(int *A,int n);
int main()
{
    int n,d,p,a[20];
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
    printf("\n");
    printf("\n enter the index which you want to find the elemet :");
    scanf("%d",&p);
    printf("\nthe element is : %d",a[(p)%n]);
    minimum(a,n,d);
    MINIMUM(a,n);
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
void minimum(int *p,int n,int d)
{
    int mid,b=0,l=n-1;
    if(p[b]>p[l])
    {
        printf("\n minimum value is %d",p[n-d]);
    }
    else
    {
        printf("\n minimum value is %d",p[b]);
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
void MINIMUM(int *p,int n)
{
    int b=0,l=n-1,mid=0;
    while(b<=l)
    {
        mid=(b+l)/2;
        if(p[mid]<p[mid+1]&&p[mid]<p[mid-1])
        {
            printf("\n%d ",p[mid]);
            break;
        }
        else if(p[mid]<p[n-1])
        {
            l=mid-1;
        }
        else
        {
            b=mid+1;
        }
    }
}
