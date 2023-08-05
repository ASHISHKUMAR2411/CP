#include<iostream>
#include<string>
using namespace std;
int main()
{
    if(0)
    {
        label1: cout<<"\n Ashish ";
        goto label2;
    }
    else
    {
        goto label1;
        label2: cout<<"Kumar";
    }
    return 0;
}