#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    // comparison of two string
    char ch1[25],ch2[25];
    printf("\n enter thr first sting which is to be compared \t");
    gets(ch1);
    printf("\n enter thr second sting which is to be compared");
    gets(ch2);
    int i=0;
    while(ch1[i]==ch2[i]&&ch1[i]!='\0'&&ch2[i]!='\0')
    i++;
    if(ch1[i]=='\0'&&ch2[i]=='\0')
    printf("\n the strings are equal");
    else
    printf("\n the string are not equal");
    return 0;
}