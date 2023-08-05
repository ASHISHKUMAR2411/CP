// two pointer technique is the twchnique which is uesd to search to for a pair in a sorted array.
// example is that sum of two pair is let say X
#include<stdio.h>
#include<stdlib.h>
void  two_pointer(int *a,int n,int k);
void sort(int *A,int n);
int main()
{
    int a[20],n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    printf("\n enter the X ");
    scanf("%d",&k);
    two_pointer(a,n,k);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
  
    sort(a,n);
    two_pointer(a,n,k);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void  two_pointer(int *a,int n,int k)
{
    int count=0,*p,*q;
    p=&a[0];
    q=&a[n-1];
    while(p<q)
    {
        if((*p+*q)<k)
        {
            p++;
        }
        else if((*p+*q)>k)
        {
            q--;
        }
        else if((*p+*q)==k)
        {
            count++;
            p++;
        }
    }
    printf("\n%d",count);
}
void sort(int *A,int n)
{
    int temp=0,j=0,i=0;
    for(j=1;j<n;j++)
    {
        temp=A[j];
        i=j-1;
        while(i>=0&&A[i]>temp)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=temp;
    }
}

