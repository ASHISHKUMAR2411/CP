#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void leap( int n);
int main()
{
    // for leap of the year 
     int m;
    printf("\n enter the year i will tell you whether that was /will be leap or not \t :");
    scanf("%u",&m);
    leap(m);
    return 0;
}
void leap( int n)
{ 
    int k=0;
    if(n%100==0)
    {
        if(n%400==0)
        {
            printf("\n %d is a leap year ",n );
        }
        else
        {
            printf("\n %d is a not  leap year",n);
        }
    }
    else if(n%4==0)
    {
        printf("\n %d is a leap year ",n);
    }
    else
    {
        printf("\n%d is not a leap year",n);
    }
}