#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char ch1[100],ch2[100],*p1,*p2,ch3,ch4;
    gets(ch1);
    gets(ch2);
    puts(ch1);
    puts(ch2);
    strcat(ch1,ch2);
    puts(ch1);
    scanf("%s",ch1);
    scanf("%c",&ch4);
    scanf("%s",ch2);
    p1=ch1;
    p2=ch2;
    while(*p1!='\0')
    {
        p1++;
    }
    while(*p2!='\0')
    {
        *p1=*p2;
        p1++;
        p2++;
    }

    printf("%s",ch1);
    
    
    
    
}