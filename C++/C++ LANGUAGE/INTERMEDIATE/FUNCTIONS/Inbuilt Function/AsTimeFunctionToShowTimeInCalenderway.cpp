// AsTimeFunctionToShowTimeInCalenderway
#include<bits/stdc++.h>
using namespace std;
int main()
{
    time_t tim;
    time(&tim);
    cout<<"Current time is : "<<asctime(localtime(&tim));
    return 0;
}