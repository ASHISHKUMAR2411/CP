#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Print(i,limit)  while(i<=limit) \
                        { \
                           printf("\n%d",i);\
                           i++;\
                        }
int main()
{
    // using multiple line in #define
    int i=0;
    Print(i,5);
    return 0;

}