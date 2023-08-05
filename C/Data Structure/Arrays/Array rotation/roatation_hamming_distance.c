#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
void hammingdistance(int *p,int n);
int main()
{
    int a[20],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    hammingdistance(a,n);
    return 0;
}
void hammingdistance(int *p,int n)
{
    int temp[50],count=0;
    for(int i=0;i<n;i++)
    {
        temp[i]=p[i];
        temp[i+n]=p[i];
    }
    for(int i=0;i<n;i++)
    {
        if(temp[i+1]!=p[i])
        {
            count++;
        }
    }
    printf("\n maximum hamming distance is : %d",count);
}