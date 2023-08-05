// something wrong in this code
#include<stdio.h>
#include<stdlib.h>
void swap(int *p,int n,int i);
int c=0;
int main()
{
    int a[20],n,d,k,count1=0,j,max;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the k ");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        count1=0;
        if(a[i]<=k)
        {
            j=i+1;
            count1++;
            max=count1;
            while(a[j]<=k && j<n)
            {
                count1++;
                j++;
            }
            if(count1>max)
            {
                max=count1;
                d=j;
            }
        }
    }
    d=d-count1;
    for(int i=0;i<d;i++)
    {
        if(a[i]<=k)
        {
            swap(a,d,i);
        }
    }
    for(int i=d+count1;i<n;i++)
    {
        if(a[i]<=k)
        {
            swap(a,n,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n%d",c-1);
    return 0;
}
void swap(int *p,int n,int i)
{
    int temp;
    temp=p[i];
    for(int j=i;j<n-1;j++)
    {
        p[j]=p[j+1];
    }
    p[n-1]=temp;
    c++;
}