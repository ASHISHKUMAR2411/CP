// Write a C++ Program to shown the concept of operator overloading
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
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real=real+c.real;
        temp.img=img+c.img;
        return temp;
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real=real-c.real;
        temp.img=img-c.img;
        return temp;
    }
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real=real*c.real-img*c.img;
        temp.img=real*c.img+img*c.real;
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.real=(real*c.real+img*c.img)/(c.real*c.real+c.img*c.img);
        temp.img=(img*c.real-real*c.img)/(c.real*c.real+c.img*c.img);
        return temp;
    }
    void display()
    {
        cout<<real<<"+"<<img<<"i"<<endl;
    }
};
int main()
{
    Complex c1,c2,c3,c4;
    cin>>c1.real>>c1.img>>c2.real>>c2.img;
    c3=c1+c2;
    c4=c1-c2;
    c3.display();
    c4.display();
    c3=c1*c2;
    c3.display();
    c3=c1/c2;
    c3.display();
    return 0;
}
// Output:
// Enter the real and imaginary part of complex number 1:
// 1
// 1
// Enter the real and imaginary part of complex number 2:
// 2
// 2
// 3+3i
// -1+1i
//
