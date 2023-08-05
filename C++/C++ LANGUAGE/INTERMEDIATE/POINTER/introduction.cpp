#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v=10;
    int *p=&v;
    cout<<p<<endl;
    (*p)++;
    cout<<*p<<endl;
    cout<<v<<endl;
    (*p)=15;
    cout<<*p<<endl;
    cout<<v<<endl;
    *p += 15;
    cout<<*p<<endl;
    cout<<&v<<endl;
    return 0;
}
