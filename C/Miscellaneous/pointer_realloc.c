#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
int main()
{
    int n;
    char ch[1];
    printf("\n enter  the number of letter in the string is  ");
    scanf("%d",&n);
    char *ptr=(char *)malloc(n*sizeof(char));
    if(ptr==NULL)
    {
        printf("\n the memory is not allocated : ");
        exit (0);
    }
    gets(ch);
    gets(ptr);
    ptr=(char *)realloc(ptr,(n+1)*sizeof(char));
    gets(ptr);
    puts(ptr);
    free(ptr);
    ptr=NULL;
    return 0;
}