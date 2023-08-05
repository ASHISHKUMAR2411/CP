// this is for another method 
#include<stdio.h>
// #include<stdlib.h>
int main()
{
    int n,a[20],sum1,max=0,sum3=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        
    }
    for(int i=0;i<n;i++)
    {
        sum1 += a[i]*i;
        sum3 += a[i];
    }
    max=sum1;
    for(int i=1;i<n;i++)
    {
        int sum2 = sum1-(sum3-a[i-1])+(a[i-1]*(n-1));
        sum1=sum2;
        if(sum2>max)
        {
            max=sum2;
        }
    }
    printf("\n sum is  %d ", max);
    return 0;
}
