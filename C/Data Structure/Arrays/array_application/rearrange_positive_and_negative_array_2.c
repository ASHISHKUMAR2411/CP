#include<stdio.h>
#include<stdlib.h>
void rearrange(int *a,int n);
int main()
{
    // motive was to bring all the negative before positive.
    // int his we are using extra space but time complexity is O(n)
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    rearrange(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void rearrange(int *a,int n)
{
    int temp[n],k=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>=0)
        {
            temp[k++]=a[i];
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<0)
        {
            temp[k++]=a[i];
        }
    }
    for(int i=0;i<k;i++)
    {
        a[i]=temp[n-1-i];
    }
}