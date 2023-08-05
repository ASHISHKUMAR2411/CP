#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int (*p)[20]=&a;
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(*p+i));
    }
    return 0;
}