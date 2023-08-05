#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void stat(void);
int main()
{
    // use of static variable 
    stat();
    stat();
    stat();
    stat();
    return 0;

}
void stat(void)
{
     static int x=0;
    x=x+1;
    printf("\n%d",x);
}