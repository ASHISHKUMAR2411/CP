#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
void space(int x);
int main()
{
    // using space(x) function to give space of x length between the two the output 
    int n;
    char s1[20],s2[100];
    printf("\n enter the string you want to print \t");
    gets(s1);
    printf("\n enter the string you want to print after the space \t");
    gets(s2);
    printf("\n enter the number of space you want to give between the two output : \t ");
    scanf("%d",&n);
    printf("%s",s1);
    space(n);
    printf("%s",s2);
    // puts(s1);
    // space(n);
    // puts(s2);
        return 0;

}
void space(int x)
{
    for(int i=0;i<x;i++)
    printf(" ");
}      
