#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int x =0;
int f()
{
    return x;
}
int g()
{
    int x=1;
    return f();
}
int main()
{
    printf("%d",g());
    printf("\n");
}