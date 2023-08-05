#include<iostream>
using namespace std;
unsigned long long int fact(int a);
int main()
{
    int a;
    unsigned long long int f;
    cout<<"enter the values whose factorial you want to find "<<endl;
    cin>>a;
    f=fact(a);
    cout<<"\n the factioal of "<<a <<"is"<<f<<endl;
    return 0;
}
unsigned long long int fact( int a)
{
    if(a==0)
    {
        return 1;
    }
    while(a>0)
    {
        return a*fact(a-1);
    }
}