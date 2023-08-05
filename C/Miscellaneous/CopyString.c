#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char ch1[50],ch2[50],ch3;
    gets(ch1);
    gets(ch2);
    int i=0;
    while(ch2[i]!='\0')
    {
        ch1[i]=ch2[i];
        i++;
    }
    ch1[i]='\0';
    puts(ch2);
    puts(ch1);
    
    return 0;
}