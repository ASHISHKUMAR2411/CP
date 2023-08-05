#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char ch[100],temp;
    gets(ch);
    n=strlen(ch);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(ch[j]>ch[j+1])
            {
                temp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=temp;                
            }
        }
    }
    printf("\n%s",ch);
}