#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{  // display will be like the first line all digit ,2nd line all except first , third all except first two;
    int n;
    char ch[10];
     
    printf("\n enter the number you want to diaplay as mention above \t ");
    gets(ch);
    n=strlen(ch);
    for(int i=0;i<n;i++)
    {
        printf("\n the %d line\t",i+1);
        for(int j=i;j<n;j++)
        {
            printf("%c",ch[j]);
        }
        
    }
    return 0;
}