#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char ch1[50],ch2[50],ch3;
    gets(ch1);
    gets(ch2);
    int i=0;
    while(ch1[i++]==ch2[i++]&& ch1[i]!='\0'&&ch2[i]!='\0');
    if(ch1[i]=='\0'&&ch2[i]=='\0')
    {
        printf("same");
    }
    else
    {
        printf("not same ");
    }
    gets(ch1);
    gets(ch2);
    if(strcmp(ch1,ch2)==0)
    {
        printf("same");
    }
    else
    {
        printf("not same ");
    }
    return 0;
}