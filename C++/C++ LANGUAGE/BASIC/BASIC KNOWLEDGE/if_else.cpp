#include<iostream>
using namespace std;
int main()
{
    static int i=0;
    if(i>0);
    else
    {
        cout<<"\nHello world";
        i++;
        main();
    }
    return 0;
}