// To show multiple inheritance
#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
    int a;
    void getdata()
    {
        cout<<"Enter a: ";
        cin>>a;
    }
};
class B
{
    public:
    int b;
    void getdata()
    {
        cout<<"Enter b: ";
        cin>>b;
    }
};
class C: public A, public B
{
    public:
    int c;
    void getdata()
    {
        cout<<"Enter c: ";
        cin>>c;
    }
};
int main()
{
    C c;
    c.getdata();
    cout<<"a: "<<c.a<<endl;
    cout<<"b: "<<c.b<<endl;
    cout<<"c: "<<c.c<<endl;
    return 0;
}
// Output:
// Enter a: 1
// Enter b: 2
// Enter c: 3
// a: 1
// b: 2
// c: 3
// Process finished with exit code 0
