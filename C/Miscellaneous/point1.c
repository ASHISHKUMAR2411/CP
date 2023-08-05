// pointer to structure 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct structure
{
    int a;
    int b;
    char c;
    char ch[30];
}s[6];
int main()
{
    struct structure *p ;
    char ch1[2];

    for(p=s;p<s+6;p++)
    {
        printf("\n enter the first value : ");
        scanf("%d",&p->a);
        printf("\n enter the second value : ");
        scanf("%d",&p->b);
        printf("\n enter the char : ");
        gets(ch1);
        scanf("%c",&p->c);
        printf("\n enter the character string : ");
        gets(p->ch);
    }
    p=s;
    while(p<s+6)
    {
        printf("\n %d%d  %c  %s ",p->a,p->b,p->c,p->ch);
        p++;
    }
    return 0;

}