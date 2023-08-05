#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
int main()
{
    int n;
    char ch[1];
    printf("\n enter the character you want to print ");
    scanf("%d",&n);
    char *ptr=(char *)malloc(n*sizeof(char));
    if(ptr==NULL)
    {
        printf("\n we have not stored the value ");
        exit (0);
    }
    for(int i=0;i<n;i++)
    {
        gets(ch);
        printf("\n enter the character : ");
        scanf("%c",ptr+i);
    }
    for(int i=0;i<n;i++)
    {
        printf("%c",*(ptr+i));
    }
    free(ptr);
    ptr=NULL;
    return 0;
}