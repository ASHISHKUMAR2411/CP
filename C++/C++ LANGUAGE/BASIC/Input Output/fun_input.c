#include<stdio.h>
#include<stdlib.h>
#include<process.h>//for exit(0) to work 
// the task is to print 10 only and we cannot change the main()
// 1st Approach 
// void fun()
// {
//     printf("10");
//     exit(0);
// }

// 2nd Approach
void fun()
{
    #define printf(x,y) printf(x,10);
}
int main()
{
    int i =10 ;
    fun();
    i = 20;
    printf("%d",i);
    return 0;
}