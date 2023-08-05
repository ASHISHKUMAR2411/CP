// window sliding technique is the techinque in which take the subarray as window panel and we move 1  unit every time .
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n,k,sum=0,max=0,i;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n entre the value of k ");
    scanf("%d",&k);
    for( i=0;i<k;i++)
    {
        sum+=a[i];
    }
    max=sum;
    while(i<n)
    {
        sum += a[i]-a[i-k];
        if(sum>max)
        {
            max=sum;
        }
        i++;
    }
    printf("\n%d",max);
}