#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum(int *, int *);
int main()
{
    // finding sum of the wo number when we have pointer
    int a = 5, b = 10, sum1;
    sum1 = sum(&a, &b);
    printf("\n%d", sum1);
}
int sum(int *a, int *b)
{
    int temp;
    temp = *a + *b;
    return (temp);
}