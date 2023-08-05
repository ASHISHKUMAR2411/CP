#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void larger(int *, int *);
int main()
{
    int a=10,b=5;
    larger(&a,&b);
    return 0;
}
void larger(int *a, int *b)
{
    if(*a>*b)
    {
        printf("\n the larger number is %d",*a);
    }
    else
    {
        printf("\n the larger number is %d",*b);
    }
}