#include<stdio.h>
#include<string.h>
int main()
{
    char str[20][20],dummy[20];
    int n,k=0,min=0;
    printf("\nenter the number of element in the string : ");
    scanf("%d",&n);
    char ch = getchar();
    for(int i=0;i<n;i++)
    {
        printf("\neneter the string : ");
        gets(str[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        min =i;
        for(int j=i+1;j<n;j++)
        {
            k=0;
            if(str[min][k]>str[j][k])
            {
                min=j;
            }
            else if(str[min][k]==str[j][k])
            {
                while(str[min][k]==str[j][k])
                {
                    k++;
                }
                if(str[min][k]>str[j][k])
                { 
                    min=j;
                }
            }
        }
        strcpy(dummy,str[i]);
        strcpy(str[i],str[min]);
        strcpy(str[min],dummy);
    }
    for(int i=0;i<n;i++)
    {
        puts(str[i]);
    }
    return 0;
}