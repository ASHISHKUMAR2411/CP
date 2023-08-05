#include<iostream>
using namespace std;
int &fun()
{
    static int x=10;
    return x;
}
int fun2(int &x)
{
    return x;
}
int main()
{
    int x=30;
    // fun()=30;
    cout<<fun()<<endl;
    cout<<fun2(x)<<endl;
    // cout<<fun2(20)<<endl;
    return 0;
}