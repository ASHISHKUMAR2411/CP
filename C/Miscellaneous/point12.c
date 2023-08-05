#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void (*p)();           // this tell the compiler that *p is a pointer to the function and it will point another function of same data type int
void *q(int *, int *); // this will tell the compiler that q is a function tha return pointer of the data type int
void mul(int *, int *);
int main()
{
    // understanding the pointer and the function
    int a = 5, b = 10, c = 20, d = 30;
    mul(&a, &b);
    q(&b, &c);
    p = mul;
    (*p)(&c, &d);
    return 0;
}

void *q(int *a, int *b)
{
    int temp;
    temp = *a * *b;
    printf("\n %d", temp);
}
void mul(int *a, int *b)
{
    int temp;
    temp = *a * *b;
    printf("\n %d", temp);
}