#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void locate(char s1[30], char s2[30], int m);
int main()
{
    // locate() and insert s2 into s1 from index m
    char s1[30],s2[30];
    int m;
    printf("\n enter the string you want to operate :\t ");
    gets(s1);
    printf("\n enter the string you want to insert in s1: \t");
    gets(s2);
    printf("\n enter the value of index after which you want to insert the s2 into s2 : \t");
    scanf("%d",&m);
    locate(s1,s2,m);
    return 0;
}
void locate(char s1[30], char s2[30], int m)
{
    char ch3[100],ch2[100];
    int k=1;
    ch2[0]=' ';
    strcpy(ch3,s1);
    for(int i=m+1;ch3[i]!='\0';i++)
    {
        ch2[k++]=ch3[i];
        ch3[i]='\0';

    }
    strcat(ch3,s2);
    strcat(ch3,ch2);
    printf("\n now the new character array is \t : %s",ch3);
}
