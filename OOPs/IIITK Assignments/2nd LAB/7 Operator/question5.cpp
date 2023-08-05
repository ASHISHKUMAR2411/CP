// Write a C++ program to overload the new and delete operator which is used for dynamically allocate and reallocated the memory for the creation and deletion of a object in a class respectively.
#include<bits/stdc++.h>
using namespace std;
class A
{
    int *p;
    public:
        A()
        {
            p=new int;
            cout<<"\nEnter the value of the object:";
            cin>>*p;
        }
        ~A()
        {
            cout<<"\nThe value of the object is:"<<*p;
            delete p;
        }
};
int main()
{
    A a;
    return 0;
}
// Output:
// Enter the value of the object:45
// The value of the object is:45