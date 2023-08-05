#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fun(int *p,int n,int *min,int *max);
int main()
{
    int n, min=0,max=0,a[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int *p=a;
    fun(p,n,&min,&max);
    printf("%d %d",min,max);
    return 0;
}
void fun(int *p,int n,int *min,int *max)
{
    *min=p[0];
    *max=p[0];
    for(int i=1;i<n;i++)
    {
        if(p[i]>*max)
        {
            *max=p[i];
        }
        if(p[i]<*min)
        {
            *min=p[i];
        }
    }
}