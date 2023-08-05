#include<stdio.h>
int global=100;
//NOTE: After compliation in terminal
//  gcc memory-layout.c -o memory-layout
// size memory-layout.exe
int main(void)
{
    static int i=100;
    return 0;
}