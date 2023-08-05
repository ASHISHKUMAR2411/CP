#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define get(a) #a
#define paste1(c,d)  c##d
int main()
{
    // this #a will convert the inout as string
    printf("\n%s",get(Ashish));
    printf("\n%s",get(Kumar));
    // printf("\n%s",paste1(get(Ashish),get(Kumar)));
    return 0;
}