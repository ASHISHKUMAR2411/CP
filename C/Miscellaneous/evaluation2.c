#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define r 5
int introwcol(char *p[]);
int main()
{
    char ch[5][20];
    printf("\n enter the 5 names when asked \t");
    for(int i=0;i<r;i++)
    {
        printf("\n enter the %d name\t",i+1);
        gets(ch[i]);
    }
    introwcol(&ch[0][0]);
    return 0;
}
int introwcol(char *p[5])
{
    char *dummy;
    int i,j;
    p=(char*)malloc(200*sizeof(char));
    for(i=0;i<5;i++)
    {
        for( j=0;j<=strlen(p[i]);j++)
        {
            dummy=*(p[i]+j);
            *(p[i]+j)=*(p[j]+i);
            *(p[j]+i)=dummy;
        }
    }
    return 0;
}
