#include<stdlib.h>
#include<stdio.h>
int main()
{
    int i=1;
    int *p,*q;
    p=&i;
    q=p;
    *q=5;
    printf("%d",*p);
    return 0;
    free(p);
    free(q);
    printf("%d",*p);
    printf("%d",*q);
    p=NULL;
    q=NULL;
    printf("%d",*p);
}