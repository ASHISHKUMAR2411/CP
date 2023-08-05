#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vect{10,20,30,40};
    for(auto i=vect.begin();i!=vect.end();i++)
    {
        cout<<"   "<<*i;
    }
    cout<<"\n";
    for(int x:vect)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    for(int &x:vect)
    {
        x += 5;
    }
    cout<<"\n";
    for(int x:vect)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto i=vect.begin();i!=vect.end();i++)
    {
        cout<<"   "<<*i;
    }
    return 0;
}