#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    // rounding off the digit 
    int n,j=0;
    char ch[50];
    printf("\n enter the number \t : ");
    gets(ch);
    n=strlen(ch);
    for(int i=0; i<n;i++)
    {
        if(isdigit(ch[i]))
        {
            if(ch[i]=='.')
        {
            j=i+2;
            if(ch[i+3]>'5')
            {
                if(ch[i+2]=='9')
                {
                    ch[i+2]='0';
                    ch[i+1]++;
                }
                else
                {
                   ch[i+2]++; 
                }
            }
        }
        }
        else
        {
            printf("enter the digit don't be oversmart/dump");
            break;
        }
    }
    for(int i=0;i<=j;i++)
    {
        if(isdigit(ch[i]))
        printf("%c",ch[i]);
    }
    return 0;
}
  