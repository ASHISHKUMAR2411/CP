#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
int main()
{
    int n;
    char ch[1];
    printf("\n enter the character you want to print ");
    scanf("%d",&n);
    char *ptr=(char *)calloc(n,sizeof(char));
    if(ptr==NULL)
    {
        printf("\n we have not stored the value ");
        exit (0);
    }
    gets(ch);
    gets(ptr);
    puts(ptr);
    free(ptr);
    ptr=NULL;
    return 0;
}