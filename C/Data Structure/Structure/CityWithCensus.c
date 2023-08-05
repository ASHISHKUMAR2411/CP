#include<stdio.h>
struct census
{
    char city[20];
    long int  population;
    float literacy_rate;
}CITY[5],temp;

int main()
{
    char ch1[1];
    for( int i=0;i<5;i++)
    {
        printf("\n enter the details of the %d cities ",i+1);
        printf("\n enter the city name : ");
        gets(CITY[i].city);
        printf("\n enter the city population :");
        scanf("%ld",&CITY[i].population);
        printf("\n enter the city litercy_rate :");
        scanf("%f",&CITY[i].literacy_rate);
        gets(ch1);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if((strcmp(CITY[j].city,CITY[j+1].city))>0)
            {
                temp=CITY[j];
                CITY[j]=CITY[j+1];
                CITY[j+1]=temp;
            }
        }
    }
    printf("\n now printing the structure in order of city alphabetically");
    for(int i=0;i<5;i++)
    {
        printf("\n\n city : %s",CITY[i].city);
        printf("\n population : %ld ",CITY[i].population);
        printf("\n literacy rate : %f",CITY[i].literacy_rate);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(CITY[j].literacy_rate>CITY[j+1].literacy_rate)
            {
                temp=CITY[j];
                CITY[j]=CITY[j+1];
                CITY[j+1]=temp;
            }
        }
    }
    printf("\n now printing the structure in order of literacy rate ");
    for(int i=0;i<5;i++)
    {
        printf("\n\n city : %s",CITY[i].city);
        printf("\n population : %ld ",CITY[i].population);
        printf("\n literacy rate : %f",CITY[i].literacy_rate);
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(CITY[j].population>CITY[j+1].population)
            {
                temp=CITY[j];
                CITY[j]=CITY[j+1];
                CITY[j+1]=temp;
            }
        }
    }
    printf("\n now printing the structure in order of population");
    for(int i=0;i<5;i++)
    {
        printf("\n\n city : %s",CITY[i].city);
        printf("\n population : %ld ",CITY[i].population);
        printf("\n literacy rate : %f",CITY[i].literacy_rate);
    }
    return 0;
}
