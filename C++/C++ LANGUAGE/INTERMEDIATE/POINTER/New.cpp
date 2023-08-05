#include<iostream>
using namespace std;
int main()
{
    // NOTE Here nothrow will make sure that if space is not given then it will be returing null and delete will remove the address 
    int *ptr = new(nothrow) int(10);
    cout<<*ptr<<" "<<ptr;
    delete ptr;
    return   0;
}