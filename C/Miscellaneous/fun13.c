#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void fun(  int a,  int b);
int main()
{
    //  use of automatic variable
   auto int a=5,b=6,c;
   fun(a,b);
   c=5;
   printf("\n%d",c);
   return 0;
}
void fun( int a ,  int b )
{
    auto int c ;
    c=a+b;
    printf("\n%d",c);
}