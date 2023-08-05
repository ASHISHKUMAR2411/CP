#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[10],n,min=0,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *p=a;
    min=p[0];
    max=p[0];
    for(int i=0;i<n;i++)
    {
        
        if(p[i]>max)
        {
            max=p[i];
        }
        if(p[i]<min)
        {
            min=p[i];
        }
        
    }
    printf("%d %d",min,max);
    return 0;
}