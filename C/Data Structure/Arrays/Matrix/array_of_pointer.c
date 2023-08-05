// it is to be remembred that the array of pointer only store adress of the varibale or any other pointer or array it cannot store the value
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *a[5],p[10];
    for(int i=0;i<5;i++)
    {
        gets(p);
        a[i]=p;
    }
    for(int i=0;i<5;i++)
    {
        printf("%s\n",a[i]);
    }
}