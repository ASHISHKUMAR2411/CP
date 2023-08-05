// Write a C++ Program to shown the concept of Virtual function also define a specific problem where we can use this concept for solving the specified problem using the Virtual function concept.
#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
        virtual void show()
        {
            cout<<"A";
        }
};
class B:public A
{
    public:
        void show()
        {
            cout<<"B";
        }
};
int main()
{
    A *a=new B();
    a->show();
    return 0;
}
// Output:
// B
// Explanation:
// In the above program, we have defined a class A and class B.
// class A is a base class and class B is a derived class.
// class B is a derived class of class A.