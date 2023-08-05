// to find next date
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Date
{
    int day;
    int month;
    int year;
} d;
struct Date Input(struct Date Q);
void Print(struct Date Q);
void validate(struct Date Q);
void Newdate(struct Date Q);
int count(int p);
int main()
{

    d = Input(d);
    validate(d);
    return 0;
}
struct Date Input(struct Date Q)
{
    printf("\n enter the day of the month : ");
    scanf("%d", &Q.day);
    printf("\n enter the month : ");
    scanf("%d", &Q.month);
    printf("\n enter the year : ");
    scanf("%d", &Q.year);
    return Q;
}
void validate(struct Date Q)
{
    if (Q.month <= 12)
    {
        switch (Q.month)
        {
        case 1:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;

        case 2:
            if (Q.year % 100 == 0)
            {
                if (Q.year % 400 == 0)
                {

                    if (Q.day <= 29)
                    {
                        Print(Q);
                        Newdate(Q);
                    }
                    else
                    {
                        printf("\n it is not a leap year so 29 day in Feb is not allowed");
                    }
                }
                else
                {
                    if (Q.day <= 28)
                    {
                        Print(Q);
                        Newdate(Q);
                    }
                    else
                    {
                        printf("\n you have entered wrong in days of  Feb is not allowed");
                    }
                }
            }
            else if (Q.year % 4 == 0)
            {
                if (Q.day <= 29)
                {
                    Print(Q);
                    Newdate(Q);
                }
                else
                {
                    printf("\n it is  a leap year so 29 day in Feb is  allowed");
                }
            }
            else
            {
                if (Q.day <= 28)
                {
                    Print(Q);
                    Newdate(Q);
                }
                else
                {
                    printf("\n you have entered wrong in days of  Feb is not allowed");
                }
            }
            break;
        case 3:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 4:
            if (Q.day <= 30)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 5:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 6:
            if (Q.day <= 30)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 7:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 8:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 9:
            if (Q.day <= 30)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 10:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 11:
            if (Q.day <= 30)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        case 12:
            if (Q.day <= 31)
            {
                Print(Q);
                Newdate(Q);
            }
            else
            {
                printf("\n number of days are not entered correctly");
            }
            break;
        default:
            printf("\n you have entered wrong month ");
            break;
        }
    }
}

void Print(struct Date Q)
{

    switch (Q.month)
    {
    case 1:
        printf("\n January %d,%d", Q.day, Q.year);
        break;
    case 2:
        printf("\n Febuary %d,%d", Q.day, Q.year);
        break;
    case 3:
        printf("\n March %d,%d", Q.day, Q.year);
        break;
    case 4:
        printf("\n April %d,%d", Q.day, Q.year);
        break;
    case 5:
        printf("\n May %d,%d", Q.day, Q.year);
        break;
    case 6:
        printf("\n June %d,%d", Q.day, Q.year);
        break;
    case 7:
        printf("\n July %d,%d", Q.day, Q.year);
        break;
    case 8:
        printf("\n August %d,%d", Q.day, Q.year);
        break;
    case 9:
        printf("\n September %d,%d", Q.day, Q.year);
        break;
    case 10:
        printf("\n October %d,%d", Q.day, Q.year);
        break;
    case 11:
        printf("\n November %d,%d", Q.day, Q.year);
        break;
    case 12:
        printf("\n december %d,%d", Q.day, Q.year);
        break;
    default:
        printf("\n You have entered the wrong for months ");
    }
}
int r;
int countl(int p)
{
    int q=0,r;
    p=p/366;
    for( int i=2;i<=p;p++)
    {
        if(i%4==0)
        {
            
        }
        else
        {
            q++;
        }
    }
    r=p%366;
    r+=q;
    return q;
}
void Newdate(struct Date Q)
{
    int n,no,z;
    printf("\n enter the number of days you want to add : ");
    scanf("%d", &n);
    Q.day += n;
    if (Q.month <= 12)
    {
        switch (Q.month)
        {
        case 1:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                if (Q.year % 100 == 0)
                {
                    if (Q.year % 400 == 0)
                    {
                        Q.year += Q.day/366;
                        no=countl(Q.day);
                        if (Q.year % 100 == 0)
                        {
                           if (Q.year % 400 == 0)
                           {
                               r = r/365;
                               Q.day=r%365;
                               Q.year += r;
                           }
                           else
                           {
                               z=Q.year + 1;
                               if (z % 100 == 0)
                               {
                                   if (z % 400 == 0)
                                   { 
                                       r=r/366;
                                       Q.day=r%366;
                                       Q.year += r;
                                   }
                                   else
                                   {
                                       r=r/365;
                                       Q.day=r%365;
                                       Q.year += r;
                                   }
                               }
                               else if (z % 4 == 0) 
                               {
                                   r=r/366;
                                   Q.day=r%366;
                                   Q.year += r;
                               }  
                               else
                               {
                                   r = r/365;
                                   Q.day=r%365;
                                   Q.year += r;
                               }
                           }  
                        }
                        else if (Q.year % 4 == 0)
                        {
                            r = r/365;
                            Q.day=r%366;
                            Q.year += r;
                        }
                        else
                        {
                           z=Q.year + 1;
                               if (z % 100 == 0)
                               {
                                   if (z % 400 == 0)
                                   { 
                                       r=r/366;
                                       Q.day=r%366;
                                       Q.year += r;
                                   }
                                   else
                                   {
                                       r=r/365;
                                       Q.day=r%365;
                                       Q.year += r;
                                   }
                               }
                               else if (z % 4 == 0) 
                               {
                                   r=r/366;
                                   Q.day=r%366;
                                   Q.year += r;
                               }  
                               else
                               {
                                   r = r/365;
                                   Q.day=r%365;
                                   Q.year += r;
                               } 
                        }
                    }
                    else
                    {
                       if((Q.day/365)>=1)
                        {
                           Q.year += 1;
                           Q.day -= 365 ;
                           if(Q.days>=365)
                           {
                               
                           }
                           else
                           {
                            //    blank
                           }
                        }
                       else
                       {
                            // blank
                       }

                    }
                } 
                else if(Q.year % 4 == 0)
                {
                    Q.year += Q.day/366;
                        no=countl(Q.day);
                        if (Q.year % 100 == 0)
                        {
                           if (Q.year % 400 == 0)
                           {
                               r = r/365;
                               Q.day=r%365;
                               Q.year += r;
                           }
                           else
                           {
                               z=Q.year + 1;
                               if (z % 100 == 0)
                               {
                                   if (z % 400 == 0)
                                   { 
                                       r=r/366;
                                       Q.day=r%366;
                                       Q.year += r;
                                   }
                                   else
                                   {
                                       r=r/365;
                                       Q.day=r%365;
                                       Q.year += r;
                                   }
                               }
                               else if (z % 4 == 0) 
                               {
                                   r=r/366;
                                   Q.day=r%366;
                                   Q.year += r;
                               }  
                               else
                               {
                                   r = r/365;
                                   Q.day=r%365;
                                   Q.year += r;
                               }
                           }  
                        }
                        else if (Q.year % 4 == 0)
                        {
                            r = r/365;
                            Q.day=r%366;
                            Q.year += r;
                        }
                        else
                        {
                           z=Q.year + 1;
                               if (z % 100 == 0)
                               {
                                   if (z % 400 == 0)
                                   { 
                                       r=r/366;
                                       Q.day=r%366;
                                       Q.year += r;
                                   }
                                   else
                                   {
                                       r=r/365;
                                       Q.day=r%365;
                                       Q.year += r;
                                   }
                               }
                               else if (z % 4 == 0) 
                               {
                                   r=r/366;
                                   Q.day=r%366;
                                   Q.year += r;
                               }  
                               else
                               {
                                   r = r/365;
                                   Q.day=r%365;
                                   Q.year += r;
                               } 
                        }

                }
                else
                {

                }
                        
                        if(Q.days>0)
                        {
                            Q.month += 1;
                            switch(Q.month)
                            {
                               case 2 : 
                                         Q.day -=29;
                                         if(Q.day<=0)
                                         {
                                            Q.day +=29 ;
                                            Print(Q);
                                            //  goto d1 ;
                                         }
                                         else 
                                         {
                                             Q.month +=1;
                                             goto d1;
                                         }  
                                         break;
                            d1: case 3: Q.day -=31;
                                        if(Q.day<=0)
                                        {
                                            Q.day+= 31;
                                            Print(Q);
                                        }
                                        else
                                        {
                                            Q.month+=1;
                                            goto d2;
                                        }
                                        break;
                            d2: case 4 : Q.day -= 30;
                                        if(Q.day<=0)
                                        {
                                            Q.day += 30;
                                            Print(Q);
                                        }
                                        else
                                        {
                                            Q.month +=1;
                                            goto d3;
                                        }
                                        break;           
                            d3: case 5: Q.day               
                            }
                        }

                    }
                    else
                    {
                        Q.year += Q.day/365;
                        printf("\n %d is a not  leap year", n);
                    }
                }
                else if (Q.year % 4 == 0)
                {
                    printf("\n %d is a leap year ", n);
                }
                else
                {
                    printf("\n%d is not a leap year", n);
                }
                Q.month += 1;
                Print(Q);
            }
            break;

        case 2:
            if (Q.year % 100 == 0)
            {
                if (Q.year % 400 == 0)
                {

                    if (Q.day <= 29)
                    {
                        Print(Q);
                    }
                    else
                    {
                        Q.day -= 29;
                        Q.month += 1;
                        Print(Q);
                    }
                }
                else
                {
                    if (Q.day <= 28)
                    {
                        Print(Q);
                    }
                    else
                    {
                        Q.day -= 28;
                        Q.month += 1;
                        Print(Q);
                    }
                }
            }
            else if (Q.year % 4 == 0)
            {
                if (Q.day <= 29)
                {
                    Print(Q);
                }
                else
                {
                    Q.day -= 29;
                    Q.month += 1;
                    Print(Q);
                }
            }
            else
            {
                if (Q.day <= 28)
                {
                    Print(Q);
                }
                else
                {
                    Q.day -= 28;
                    Q.month += 1;
                    Print(Q);
                }
            }
            break;
        case 3:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 4:
            if (Q.day <= 30)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 30;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 5:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 6:
            if (Q.day <= 30)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 30;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 7:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 8:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 9:
            if (Q.day <= 30)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 30;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 10:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 11:
            if (Q.day <= 30)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 30;
                Q.month += 1;
                Print(Q);
            }
            break;
        case 12:
            if (Q.day <= 31)
            {
                Print(Q);
            }
            else
            {
                Q.day -= 31;
                Q.month += 1;
                Print(Q);
            }
            break;
        default:
            printf("\n you have entered wrong month ");
            break;
        }
    }
    else
    {
        printf("\n you have entered the wrong months detail ");
    }
}