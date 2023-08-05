#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // here if you change the value of the a then it will currectly change the value of the b also and vice versa
    int a=10;
    int &b=a;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    cout<<7<<endl;
    b=20;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    a=10;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    return 0;
}