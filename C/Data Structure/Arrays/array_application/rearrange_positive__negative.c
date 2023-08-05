#include<stdio.h>
#include<stdlib.h>
void rearrange(int *a,int n);
int main()
{
    // motive was to bring all the negative before positive.
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    rearrange(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void rearrange(int *a,int n)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]>0)
                {
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
            }
        }
    }
}