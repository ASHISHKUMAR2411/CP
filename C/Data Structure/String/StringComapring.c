#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    // here we will compare the string and find out whether they are equal ar greater or smaller
    int n,n1,n2;
    char ch1[50],ch2[50];
    printf("\n enter the string \t");
    gets(ch1);
    printf("\nenter the string 2 which you want to compare \t ");
    gets(ch2);
    printf("\n enter the number of letter of string 1 you want to compare \t ");
    scanf("%d",&n);
    n1=strlen(ch1);
    n2=strlen(ch2);
    if(strncmp(ch1,ch2,n)==0)
    {
        printf("\n the substring os string 1 is equal to string 2");
        if(n1>n2)
        {
            printf("\nfirst string is greater than second string");
        }
        else if(n1==n2)
        {
            printf("\n first string is equal to second string");
        }
        else
        {
            printf("\nthe first string is less than the second string");

        }

    }
     else if(strncmp(ch1,ch2,n)>0)
    {
        printf("\n the substring os string 1 is greater tham string 2");
        if(n1>n2)
        {
            printf("\nfirst string is greater than second string");
        }
        else if(n1==n2)
        {
            printf("\n first string is equal to second string");
        }
        else
        {
            printf("\nthe first string is less than the second string");

        }

    }
    else
    {
        printf("\n the substring os string 1 is less than string 2");
        if(n1>n2)
        {
            printf("\nfirst string is greater than second string");
        }
        else if(n1==n2)
        {
            printf("\n first string is equal to second string");
        }
        else
        {
            printf("\nthe first string is less than the second string");

        }

    }
    return 0;
}