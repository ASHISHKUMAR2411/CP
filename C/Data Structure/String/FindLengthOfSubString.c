#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s1[20],s2[20],s3[20];
    printf("\nenter the string 1\t");
    gets(s1);
    printf("\nenter the string 2\t");
    gets(s2);
    int i=0;
    while(s1[i]==s2[i]&&s1[i]!='\0'&&s2[i]!='\0')
    i++;
    if(s1[i]=='\0'&&s2[i]=='\0')
    {
    }
    else
    {
        strcat(s1,s2);

    }
    strcpy(s3,s1);
    printf("\n");
    puts(s1);
    printf("\n the length of s1 %d ",strlen(s1));
    printf("\n");
    puts(s2);
    printf("\nthe length of s2 %d ",strlen(s2));
    printf("\n");
    puts(s3);
    printf("\nthe length of s3 %d",strlen(s3));
    return 0;
}