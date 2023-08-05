// determining the length of the string
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int count=0;
    char ch[50],*p;
    printf("\n enter the string  ");
    gets(ch);
    p=ch;
    while ((*p)!='\0')
    {
        count++;
        p++;
        /* code */
    }
    printf("\n %d",count);
    return 0;
}