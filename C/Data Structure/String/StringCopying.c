#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char st1[10],st2[20];
    gets(st1);
    gets(st2);
    printf("%s",strncpy(st1,st2,sizeof(st1)));
    return 0;
}