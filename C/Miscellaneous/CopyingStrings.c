#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char ch1[50],ch2[50],ch3,*p1,*p2;
    gets(ch1);
    gets(ch2);
    p1=ch1;
    p2=ch2;
    int i=0;
    while(*p2!='\0')
    {
        *p1=*p2;
        p1++;
        p2++;
    }
    *p1='\0';
    puts(ch2);
    puts(ch1);
    
    return 0;
}