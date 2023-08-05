#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int len=0;
    char string[50],*p,ch;
    scanf("%s",string);
    scanf("%c",&ch);
    p=string;
    while(*p!='\0')
    {
        len++;
        p++;
 
    }
    printf("%d",len);
    printf("\n enter again");
    gets(string);
    puts(string);
    len=strlen(string);
    printf("%d",len);
    return 0;
}