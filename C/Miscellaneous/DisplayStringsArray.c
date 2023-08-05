#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    // to display the output as follows 
    int n,i,j,k=0;
    char ch1[50];
    printf("\n enter the string \t ");
    gets(ch1);
    n=strlen(ch1);
    for( i=0;i<=n/2;i++)
    {
        for(j=n/2-1;j>=i;j--)
        {
            printf(" ");
        }
        for( j=i;j<=k;j++)
        {
            printf("%c",ch1[j]);
        }
        for(j=k-1;j>=i;j--)
        {
            printf("%c",ch1[j]);
        }
        k+=2;
        printf("\n");
    }
    return 0;
}