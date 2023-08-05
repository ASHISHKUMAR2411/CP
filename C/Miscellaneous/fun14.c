#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 int a=8;
 float b=8.0;
 int acu(int a,float b);
int main()
{
    // using global variable
    int a =4;
    float b=5.0;
    double c, sum=a+b;
    printf("%lf",sum);
   {
       extern int a;
       extern float b;
       c= acu(a,b);


   }
   printf("\n%lf",c);
   return 0 ;
}
int acu(int a, float b)
{
    double c=a+b;
    printf("\n%lf",c);
    return c;
}
