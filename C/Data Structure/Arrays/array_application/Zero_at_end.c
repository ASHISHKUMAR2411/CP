#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rotate(int *p,int n,int i);
int main()
{
    int a[20],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            rotate(a,n,i);
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
void rotate(int *p,int n,int i)
{
    int temp;
    temp=p[i];
    for(int j=i;j<n-1;j++)
    {
        p[j]=p[j+1];
    }
    p[n-1]=temp;
}