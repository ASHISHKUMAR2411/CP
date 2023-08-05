#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    //  casting pointer
    int a=97,*p;
    char *ch;
    p=&a;
    ch=(char *)p;
    printf("\n %d %d %d %d %c %p",a,p,*p,ch,*ch,ch);

}