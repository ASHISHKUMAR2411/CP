#include<stdio.h>
#include<string.h>


int main()
{
    char string[5][20],dummy[20];
    int i=0,j=0;
    printf("\n enter the name of 5 item ");
    while(i<5)
    { 
        printf("\n enter the %d string ",i+1);
        scanf("%s",string[i++]);
    }  
    for(i=1;i<5;i++)
    {
        for(j=1;j<+5;j++)
        {
            if(strcmp (string[j-1],string[j]) >0)
            {
                strcpy(dummy,string[j-1]);
                strcpy(string[j-1],string[j]);
                strcpy(string[j],dummy);
            }
        }
    }
    printf("\n Alphabetical list is \n \n");
    for(i=0;i<5;i++)
    printf("\n %s",string[i]);
    return 0;
}
