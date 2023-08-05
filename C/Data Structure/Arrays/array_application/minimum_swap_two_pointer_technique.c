#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n,count=0,min=0,k=0,i=0,l=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter the value of k ");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)
         {
            l++;
         }
    }
    
    for(i=0;i<l;i++)
    {
        if(a[i]>k)
        {
            count++;
        }
    }
    min=count;
    while(i<n)
    {
        if(a[i]>k)
        {
            count++;
        }
        if(a[i-k]>k)
        {
            count--;
        }
        if(count<min)
        {
           min=count;
        }
        i++;
    }
    printf("\n%d",min);
    return 0;
}