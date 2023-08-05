// this is for using the rotate when we find an element with out of place and rotate till opposite sign element is encountered .
#include<stdio.h>
#include<stdlib.h>
void rotate(int *a,int i,int j,int n);
int main()
{
    int a[20],n,j=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(a[i]>=0)
            {
                j=i;
                while(a[j]>=0 && j<n)
                {
                    j++;
                }
                if(a[j]<0)
                {
                    rotate(a,i,j,n);
                }
            }
        }
        else
        {
            if(a[i]<0)
            {
                j=i;
                while(a[j]<0 && j<n)
                {
                    j++;
                }
                if(a[j]>=0)
                {
                    rotate(a,i,j,n);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void rotate(int *a,int i,int j,int n)
{
    int temp;
    i=i%n;
    j=j%n;
    temp=a[j];
    for( int k=j;k>i;k--)
    {
        a[k]=a[k-1];
    }
    a[i]=temp;
}