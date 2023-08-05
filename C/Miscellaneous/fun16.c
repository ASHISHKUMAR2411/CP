#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
static int x=5;
static int y=6;
void interchange( );
int main()
{
    // use a function to interchange two variable value 
    
    interchange(s);
    printf("%d\t%d",x,y);
    return 0;

}
void interchange()
{
    extern int x,y;
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("%d\t%d\n",x,y);

}