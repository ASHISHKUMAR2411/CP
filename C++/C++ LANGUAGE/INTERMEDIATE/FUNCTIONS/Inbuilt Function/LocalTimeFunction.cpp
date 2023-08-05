// LocalTimeFunction
#include<bits/stdc++.h>
using namespace std;
int main()
{
    time_t tim;
    tim = time(NULL);
    tm *local = localtime(&tim);
    cout<<"Current time is : "<<local->tm_hour<<":"<<local->tm_min<<":"<<local->tm_sec;
    return 0;
}