#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define r 5
int strorder(char *p[5]);
int main()
{
    char ch[5][20];
    int n ;
    printf("\n enter the names when asked \t:");
    for(int i=0;i<r;i++)
    {
        printf("\n enter the %d name :",i+1);
        gets(ch[i]);
    }
    strorder(&ch[0][0]);
    return 0;
}
int strorder(char *p[5])
{   
    char *dummy[20];
    int j,i;
     j=r;
    for( i=0;i<j/2;i++)
    {
        strcpy(dummy,*p[i]);
        strcpy(*p[i],*p[j-1]);
        strcpy(*p[j-1],dummy);
        j--;
    }
    for(i=0;i<r;i++)
    {
        printf("\n%s",p[i]);
    }
    return 0;
}
