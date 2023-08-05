#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
int main()
{
    int a[10];
    int (*p)[10]=&a;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",(*p+i));
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(*p+i));
    }
}