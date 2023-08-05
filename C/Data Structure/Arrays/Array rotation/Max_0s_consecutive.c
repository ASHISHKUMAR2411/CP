#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max0s(int *p,int n);
int main()
{
    int a[20],n,d,max=0;
    label:
    printf("\n enter size : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0 || a[i]==1)
        {
            continue;
        }
        else
        {
            printf("\n you ahve entered the wrong number enter only binary:");
            printf("\n okay relax try again");
            goto label;
        }
    }
     max=max0s(a,n);
     printf("\n the maximum zero is : %d",max);
     return 0;
}
int max0s(int *p,int n)
{
    int temp[50],count=0,max=0;
    for(int i=0;i<n;i++)
    {
        temp[i]=p[i];
        temp[i+n]=p[i];
    }
    max=0;
    for(int i=0;i<2*n;i++)
    {
        count=0;
        while(temp[i]==0)
        {
            count++;
            i++;
        }
        if(count>max)
        {
            max=count;
        }
    }
    return max;  
}