// To show exapmle of single inheritance
#include <bits/stdc++.h>
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
class B:public A
{
    public:
    int b;
    void getdata()
    {
        cout<<"Enter b: ";
        cin>>b;
    }
};
int main()
{
    B obj;
    obj.getdata();
    cout<<"a: "<<obj.a<<endl;
    cout<<"b: "<<obj.b<<endl;
    return 0;
}

// Output:
// Enter a: 10
// Enter b: 20
// a: 10
// b: 20