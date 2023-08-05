#include<stdlib.h>
#include<stdio.h>
int main()
{
    int a[20],min,i,j=0,k=0,n,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        for(j=i;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                k=j;
            }
        }
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}