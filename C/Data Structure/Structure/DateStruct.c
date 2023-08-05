// to modify the date
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