#include<iostream>
using namespace std;
int f1()
{
    return 5;
}
int f2()
{
    return 10;
}
// as - has associativity as left to right but it is not the case with always as this complier dependent .
int main()
{
    int x = f1() - f2();
    cout<<x;
    return 0;
}