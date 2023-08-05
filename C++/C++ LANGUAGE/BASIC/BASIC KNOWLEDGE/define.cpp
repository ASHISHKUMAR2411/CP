#include<iostream>
using namespace std;
#define lim 10
int main()
{
    for(int i=0;i<lim;i++)
    {
       cout<<"\nHello World"; 
    }
    #ifdef lim
    cout<<"\n Hello Ashish";
    #endif
    #undef lim
    #ifndef lim
    cout<<"\n Hello Sunaina";
    #endif
    return 0;
}