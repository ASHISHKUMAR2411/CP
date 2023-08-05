#include<stdio.h>
#include<stdlib.h>
int main()
{
    int days,noofyears,n,count,months,m,daysleft,daysoff,year,dayformonths,daysleftout;
    printf("\n enter the number of days you want to convert \t");
    scanf("%d",&days);
    count=0;
    do
    {
        /* code */noofyears=days/365;
        noofyears-=4;
        count++;

    } while (noofyears>3);
    n=days/365;
    if (n<4)
    {
        year=n;
        
        
    }
    else
    {
        daysleft=days-count;
        year=(daysleft)/365;

    }
    daysoff=days-(year*365);
    m=daysoff/30;
    if(m<2)
    {
        months=m;
    }
    else
    {
        daysoff-=(m/2);
        months=daysoff/30;
    }
    daysleftout=daysoff-(months*30);
     printf("\n the year \t :%d years \n the months \t:%d months \n the days \t:%d days",year,months,daysleftout);
    return 0;
}