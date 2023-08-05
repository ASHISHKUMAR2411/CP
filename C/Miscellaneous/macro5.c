#include<stdio.h>
#define square(x) x*x
int main()
{
    // as macro are inline function i.e where ever they are called they just replace as it is
    // forexample want to expect ans as 1 for 36/36 or 36/square(6) but it will 36 as ans as it is inline
    int p=36/square(6);
    printf("%d",p);
    return 0;
}