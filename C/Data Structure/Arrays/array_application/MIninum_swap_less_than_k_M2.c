#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n,k,temp=0,count=0,d=0,l=0,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter the k ");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        d=0;
        if(a[i]<=k)
        {
            l=i+1;
            d++;
            while(a[l]<=k && l<n)
            {
                d++;
                l++;
            }
            if(d>max)
            {
                max=d;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>k)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        if(a[i]<=k)
        {
            count++;
        }
    }
    printf("\n%d",(count-max));
    return 0;
}