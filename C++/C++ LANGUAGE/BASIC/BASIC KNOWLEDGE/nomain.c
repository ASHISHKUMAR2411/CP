#include<stdio.h>
#include<stdlib.h>
void _start()
{
    int x=my_fun();
    exit(x);
}
// gcc -o exam exam.c
// objdump -f exam.exe
// objdump --disassemble exam.exe
// gcc -nostartfiles -o nomain nomaic.c
// nomain.exe
int my_fun()
{
    printf("Hello World\n");
    return 0;
}