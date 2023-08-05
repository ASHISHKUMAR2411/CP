// Write a C++ Program to shown the concept of Function Overriding also define a specific problem where we can use this concept for solving the specified problem using the Function Overriding.
#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
        void show()
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
class C:public A
{
    public:
        void show()
        {
            cout<<"C";
        }
};
class D:public B,public C
{
    public:
        void show()
        {
            cout<<"D";
        }
};
int main()
{
    D d;
    d.show();
    return 0;
}
// Output:
// D
// Time Complexity: O(1)
// Space Complexity: O(1)
//