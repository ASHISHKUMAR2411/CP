#include<stdio.h>
#include<string.h>
 int main()
{    int i,j;
    char *p[5],*temp;
    printf("\n enter the strings of character on which u want to sort ");
    for( i=0; i<5;i++)
    { 
        printf("\nenter the %d string",i+1);
        gets(p[i]);
    }
    for(i=0;i<5;i++)
    { 
        for( j=0;j<5;j++)
        {
            if((strcmp(p[i],p[i+1]))>0)
            {
                temp=p[i];
                p[i]=p[i+1];
                p[i+1]= temp;
            }
        }
    }
    return 0;
}