// using pointer exchanging the value of two places
#include<stdio.h>
int main()
{
    int a,b,*p,*q,t;
    printf("\n enter the two values you want to interchange : ");
    scanf("%d %d",&a,&b);
    p=&a;
    q=&b;
    t=*p;
    *p=*q;
    *q=t;
    printf("\n %d %d",a,b);
}