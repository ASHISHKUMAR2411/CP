// Write a C++ Program to overload the assignment(=) and equal to(==) operator by writing the definition of both the operator function through exchanging their actual operation with each other.
#include<bits/stdc++.h>
using namespace std;
class Complex
{
    int real,img;
    public:
    Complex()
    {
        real=0;
        img=0;
    }
    Complex(int r,int i)
    {
        real=r;
        img=i;
    }
    Complex operator=(Complex c)
    {
        real=c.real;
        img=c.img;
        return *this;
    }
    bool operator==(Complex c)
    {
        if(real==c.real && img==c.img)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};
int main()
{
    Complex c1(2,3),c2(4,5);
    c1=c2;
    c1.display();
    if(c1==c2)
    {
        cout<<"Both are equal"<<endl;
    }
    else
    {
        cout<<"Not equal"<<endl;
    }
    return 0;
}
// Output:
// 4+5i
// Both are equal