#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Time
{
    char ch;
    int hour;
    int min;
    int sec;
}t;
struct Time Input(struct Time T);
void Output(struct Time P);
void Update(struct Time Q);
int main()
{
    // using function to find time 
    t=Input(t);
    Output(t);
    Update(t);
    return 0;
}
struct Time Input(struct Time T)
{
    printf("\n before entering the time give deatail of am or pm by denoting them as A/a or P/p : ");
    scanf("%c",&T.ch);
    printf("\n enter the time by hours : ");
    scanf("%d",&T.hour);
    printf("\n enter the time by minutes : ");
    scanf("%d",&T.min);
    printf("\n enter the time by seconds : ");
    scanf("%d",&T.sec);
    return (T);
}
void Output(struct Time P)
{
   if(P.ch=='A' || P.ch=='a')
    {
        printf("\n the time is : %d:%d:%d ",P.hour,P.min,P.sec);
    }
    else
    {
        printf("\n the time is : %d:%d:%d ",P.hour+12,P.min,P.sec);

    }
}
void Update(struct Time Q)
{
    printf("\n the updated time is when it is added by 10 sec : ");
    Q.sec+=10;
    if(Q.sec==60)
    {
        Q.sec=0;
        Q.min+=1;
        if(Q.min==60)
        {
            Q.min=0;
            Q.hour+=1;
            if(Q.ch=='p'||Q.ch=='P')
            {
                Q.hour+=12;
                if(Q.hour<=24)
                {
                    if(Q.hour==24)
                    {
                        Q.hour=0;
                        Q.ch='A';
                        printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
                    }
                    else
                    {
                        printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
                    }
                }
                else
                {
                    printf("this is not possible time you have enter valid time and am/pm");
                }
            }
            else if((Q.ch=='a'||Q.ch=='A')&& Q.hour<12)
            {
                printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
                
            }
            else
            {
                Q.ch='P';
                printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
            }
        }
        else if(Q.min>60)
        {
            printf("\n You have given wrong instruction about minutes");
        }
        else
        {
            printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
        }
    }
    else if(Q.sec>=70)
    {
        printf("\n you have given wromh instruction about seconds");
    }
    else if( Q.sec>60 && Q.sec<=69)
    {
        Q.sec -=60;
        Q.min+=1;
        if(Q.min==60)
        {
            Q.min=0;
            Q.hour+=1;
            if(Q.ch=='p'||Q.ch=='P')
            {
                Q.hour+=12;
                if(Q.hour<=24)
                {
                    if(Q.hour==24)
                    {
                        Q.hour=0;
                        Q.ch='A';
                        printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
                    }
                    else
                    {
                        printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
                    }
                }
                else
                {
                    printf("this is not possible time you have enter valid time and am/pm");
                }
            }
            else if((Q.ch=='a'||Q.ch=='A')&& Q.hour<12)
            {
                printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
                
            }
            else
            {
                Q.ch='P';
                printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
            }
        }
        else if(Q.min>60)
        {
            printf("\n You have given wrong instruction about minutes");
        }
        else
        {
            printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec);
        }
    }
    else 
    {
       printf("\n the time is : %d:%d:%d ",Q.hour,Q.min,Q.sec); 
    }

}