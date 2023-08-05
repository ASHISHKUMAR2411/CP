#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int a,b,c,d,e;
    printf("\n enter the four numbers by giving spaces \t");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    e=(a>b)?((a>c)?((a>d)?a:d):((c>d)?c:d)):((b>c)?((b>d)?b:d):((c>d)?c:d));
    printf("\n the largest no is %d\t",e);
    return 0;

}