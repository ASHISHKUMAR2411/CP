#include<iostream>
using namespace std;
void age()
{
    int ag;
    cout<<"\nenter the age";
    cin>>ag;
    cout<<ag<<" is your age "<<endl;
}
int main()
{
    // in this we are creating the and checking the scope and declaration of different variable 
    int a;
    cin>>a;
    cout<<a<<endl;
    age();
    // cout<<age()<<endl;
    // cout<<ag<<endl;
    return 0;
}