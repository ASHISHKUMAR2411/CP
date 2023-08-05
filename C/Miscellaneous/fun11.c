#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
   
   int x=4,y=5,z=6;
   f1(x,y);
   f2(&y,&z);
   printf("%d",z-x-y);
   return 0;

}
void f1(int a,int b)
{
    int c;
    c=a;a=b;b=c;
}
void f2(int *a,int *b)
{
    int *c;
    c=*a;*a=*b;*b=c;
}