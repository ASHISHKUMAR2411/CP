// Write a C++ program to create a class Country, State, City and Village and arrange them in hierarchical manner using the Inheritance feature.

#include<bits/stdc++.h>
using namespace std;

class Country
{
    public:
    string name;
    Country(){
        cout<<"Enter Country Name : ";
        // we are using two getline because to deal with stream buffer of n in int main as we press enter the firstline will have it input as enter key so deal with it we use two getline
        getline(cin,name);
        getline(cin,name);
    }
};

class State : public Country
{
    public:
    string stateName;
    State(){
        cout<<"Enter State Name : ";
        getline(cin,stateName);
    }
};

class City : public State
{
    public:
    string cityName;
    City(){
        cout<<"Enter City Name : ";
        getline(cin,cityName);
    }
};

class Village : public State
{
    public:
    string villageName;
    Village(){
        cout<<"Enter Village Name : ";
        getline(cin,villageName);
    }
};

// Driver code
int main()
{
    int n;
    cout<<"Enter 1 if your are from city or 2 if you are from village : ";
    cin>>n;
    if(n==1)
    {
        City c;
        cout<<"You are from "<<c.cityName<<" in "<<c.stateName<<" in "<<c.name<<endl;
    }
    else if(n==2)
    {
        Village v;
        cout<<"You are from "<<v.villageName<<" in "<<v.stateName<<" in "<<v.name<<endl;
    }
    return 0;
}

// Output:
// Enter Country Name : India
// Enter State Name : Karnataka
// Enter City Name : Bangalore
// Enter 1 if your are from city or 2 if you are from village : 1
// You are from Bangalore in Karnataka in India
// Enter 1 if your are from city or 2 if you are from village : 2
// You are from Kothagudem in Karnataka in India
// 
