#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    char ch[34];
    printf("\n enter the character string you want to print like this ");
    gets(ch);
    n=strlen(ch);
    printf("\n%s",ch);
    printf("\n%15s",ch);
    printf("\n%1s",ch);
    printf("\n%*.*s",n,5,ch);
    printf("\n%.*s",4,ch);
    printf("\n%*.*s",n,0,ch);
    printf("\n%s",ch);

    return 0;
}