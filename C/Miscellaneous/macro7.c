#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define a 2
int main()
{ 
    // to see the use #ifdef,#ifndef,#undef,
    // here #ifdef is used for the checking whether the identifier is declared using #define or not they give true value when it is defined 
    // here #ifndef is used for checking whether the identifier is not defined  by #define , they give true value 1 when it is not define
    //  #undef is used undefine the define identifier by #define
    // we can also use #else,#elif,are used for the else and else if condition 
    // #endif is used to end the if statements  
    int b;
    #ifdef a
    printf("\n yes a is declared in #define ");
    #endif
    #undef a
    #ifndef a
    printf("\n no b is not #define");
    #endif
    return 0;
}