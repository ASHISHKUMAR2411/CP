// in this we are finding k consecutive number whose sum is greatest in the array 
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n,k,j,max,count,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter the k ");
    scanf("%d",&k);
    max=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        count=0;
        j=i;
        while(j<n && count<k)
        {
            sum += a[j];
            j++;count++;
        }
        if(sum>max)
        {
            max=sum;
        }
    }
    printf("\n%d",max);
    return 0;
}