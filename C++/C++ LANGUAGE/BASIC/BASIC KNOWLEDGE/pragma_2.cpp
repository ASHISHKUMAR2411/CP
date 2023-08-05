#include<iostream>
// using namespace std;
#pragma warn-rvl
#pragma warn-par
#pragma warn-rch
int call(int a,int b)
{
    std::cout<<2*a;
    return 2*a;
    std::cout<<"hello world";
}
int main()
{
    int a,b;
    std::cin>>a>>b;
    b=call(a,b);
    return 0;
}

