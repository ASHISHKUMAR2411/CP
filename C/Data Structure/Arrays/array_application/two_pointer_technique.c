// two pointer technique is the twchnique which is uesd to search to for a pair in a sorted array.
// example is that sum of two pair is let say X
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int a[20],n,x,l=0,m=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter X ");
    scanf("%d",&x);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((a[i]+a[j])==x && j!=i)
            {
                l=i;
                m=j;
                printf("\n we have %d %d index whose sum is %d ",l,m,x);
            }
        }
        
    }
    

}