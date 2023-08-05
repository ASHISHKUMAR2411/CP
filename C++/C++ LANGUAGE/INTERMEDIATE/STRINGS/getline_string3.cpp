// CPP program to find the another usage of the getline() function
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    string str , ttr;
    getline(cin,str);
    stringstream X(str);
    while(getline(X,ttr,' '))
    {
        cout<<ttr<<endl;
    }
    return 0;
}