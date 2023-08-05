#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define paste(a, b) a##b
int main()
{
    int a3 = 2;
    // showing how  paste to paste two number in macro
    printf("%d", paste(24, 34));
    printf("\n%d", paste(a, 4));
    return 0;
}