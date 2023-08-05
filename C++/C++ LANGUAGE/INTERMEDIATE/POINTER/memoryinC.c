#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int *temp = (int *)malloc(sizeof(int));
    memset(temp,0,sizeof(int));// it is used to  store 0 oly and other values gets otherwise.
    printf("%d ", *temp);
    return 0;
}