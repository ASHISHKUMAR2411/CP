#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Time
{
    char ch;
    int hour;
    int min;
    int sec;
}t;
int main()
{
    printf("\n before entering the time give deatail of am or pm by denoting them as A/a or P/p : ");
    scanf("%c",&t.ch);
    printf("\n enter the time by hours : ");
    scanf("%d",&t.hour);
    printf("\n enter the time by minutes : ");
    scanf("%d",&t.min);
    printf("\n enter the time by seconds : ");
    scanf("%d",&t.sec);
    if(t.ch=='A' || t.ch=='a')
    {
        printf("\n the time is : %d:%d:%d ",t.hour,t.min,t.sec);
    }
    else
    {
        printf("\n the time is : %d:%d:%d ",t.hour+12,t.min,t.sec);

    }
    
}