#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rotate(int *p,int d,int n);
int main()
{
    int a[10];
    int n,d;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the d for rotation i.e how many element you want to rotate :");
    scanf("%d",&d);
    rotate(a,d,n);
    return 0;
}
void rotate(int p[],int d,int n)
{
    int j,temp;
    for(int i=0;i<d;i++)
    {
        temp=p[0];
        for ( j=0;j<(n-1);j++)
        {
            p[j]=p[j+1];
        }
        p[j]=temp;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", p[i]);
    }
}
