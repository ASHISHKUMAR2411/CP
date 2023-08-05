#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef int I;
typedef char C;
int main()
{
    enum day{Monday,Tuesday,Wednesday,Friday,saturday,Sunday};
    enum day week_st,week_end;
    week_st = Monday;
    week_end= Friday;
    if(week_st==Tuesday)
     week_end=saturday;
     return 0;
}