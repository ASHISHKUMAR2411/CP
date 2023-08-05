// pointer started
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(void)
{
    int *p, a[3] = {1, 2, 3}, **q, **z, **n, *r, *s, *t, *u, *v;

    p = a;
    r = &a[0];
    v=a+1;
    s = &a[1];
    t = &a[2];
    u = s;
    q = &p;
    printf("\n %d %d %d ", q, *q, **q);
    printf("\n%d ", ++**q);
    printf("\n%d", ++*q);
    printf("\n%d", ++q);
    // printf("\n%d ", **q++);
    printf("\n%d", *q++);                                    
    printf("\n%d", q++);
    z = &s;
    n = &r;
    printf("\n %d, %d, %d ,%d ,%d ,%d ,%d, %d, %d ,%d, %d, %d ,%d ,%d, %d, %d ", a, *p, q, z, n, *q, *z, *n, **q, **z, **n, u, r, s, t, v);
    printf("\n %d %d %d",a[0],a[1],a[2]);
}