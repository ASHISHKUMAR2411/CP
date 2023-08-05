// there is some problrm in this program it is perfectly good running but output is not as expected.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ch[4][4],ch1[1];
    int n,m;
    scanf("%d %d",&n,&m);
    gets(ch1);
    char (*p)[4][4]=&ch;
    for(int i=0;i<n;i++)
    {
        scanf("%s",(*p+i));
        gets(ch1);
    }

    for(int i=0;i<n;i++)
    {
        printf("\n%s",(*p+i));
    }
}