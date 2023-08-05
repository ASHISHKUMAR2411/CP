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
    while(*p1!='\0' || *p2 != '\0')
    {
        if(*p1==*p2)
        {
            p1++;
            p2++;
        }
        else
        {
            printf("not same");
        }

    }
    if(*p1=='\0'&&*p2=='\0')
    {
        printf("same");
    }
    printf("\n");
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