// Program for hierarchical inheritance
#include <bits/stdc++.h>
using namespace std;
class A
{
    public:
    int a;
    A()
    {
        a=10;
    }
};
class B:public A
{
    public:
    int b;
    B()
    {
        b=20;
    }
};
class C:public B
{
    public:
    int c;
    C()
    {
        c=30;
    }
};
int main()
{
    C c;
    cout<<"Value of c.a is "<<c.a<<endl;
    cout<<"Value of c.b is "<<c.b<<endl;
    cout<<"Value of c.c is "<<c.c<<endl;
    return 0;
}
// Output:
// Value of c.a is 10
// Value of c.b is 20
// Value of c.c is 30