#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[20],n;
    scanf("%d",&n);
    for(int i=n-1;i>=0;i--)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}