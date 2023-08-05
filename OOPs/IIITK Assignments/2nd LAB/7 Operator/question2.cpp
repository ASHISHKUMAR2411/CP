// Write a C++ Program to overload all the Logical Operators in a single program using the friend function based concept.
#include<bits/stdc++.h>
using namespace std;
class Complex
{
    int real,img;
    public:
    friend ostream& operator<<(ostream&,Complex&);
    friend istream& operator>>(istream&,Complex&);
    friend Complex operator+(Complex&,Complex&);
    friend Complex operator-(Complex&,Complex&);
    friend Complex operator*(Complex&,Complex&);
    friend Complex operator/(Complex&,Complex&);
    friend bool operator==(Complex&,Complex&);
    friend bool operator!=(Complex&,Complex&);
    friend bool operator<(Complex&,Complex&);
    friend bool operator>(Complex&,Complex&);
    friend bool operator<=(Complex&,Complex&);
    friend bool operator>=(Complex&,Complex&);
};
ostream& operator<<(ostream& out,Complex& c)
{
    out<<c.real<<"+"<<c.img<<"i";
    return out;
}
istream& operator>>(istream& in,Complex& c)
{
    in>>c.real>>c.img;
    return in;
}
Complex operator+(Complex& c1,Complex& c2)
{
    Complex c;
    c.real=c1.real+c2.real;
    c.img=c1.img+c2.img;
    return c;
}
Complex operator-(Complex& c1,Complex& c2)
{
    Complex c;
    c.real=c1.real-c2.real;
    c.img=c1.img-c2.img;
    return c;
}
Complex operator*(Complex& c1,Complex& c2)
{
    Complex c;
    c.real=c1.real*c2.real-c1.img*c2.img;
    c.img=c1.real*c2.img+c1.img*c2.real;
    return c;
}
Complex operator/(Complex& c1,Complex& c2)
{
    Complex c;
    c.real=(c1.real*c2.real+c1.img*c2.img)/(c2.real*c2.real+c2.img*c2.img);
    c.img=(c1.img*c2.real-c1.real*c2.img)/(c2.real*c2.real+c2.img*c2.img);
    return c;
}
bool operator==(Complex& c1,Complex& c2)
{
    if(c1.real==c2.real && c1.img==c2.img)
        return true;
    else
        return false;
}
bool operator!=(Complex& c1,Complex& c2)
{
    if(c1.real!=c2.real || c1.img!=c2.img)
        return true;
    else
        return false;
}
bool operator<(Complex& c1,Complex& c2)
{
    if(c1.real<c2.real && c1.img<c2.img)
        return true;
    else
        return false;
}
bool operator>(Complex& c1,Complex& c2)
{
    if(c1.real>c2.real && c1.img>c2.img)
        return true;
    else
        return false;
}
bool operator<=(Complex& c1,Complex& c2)
{
    if(c1.real<=c2.real && c1.img<=c2.img)
        return true;
    else
        return false;
}
bool operator>=(Complex& c1,Complex& c2)
{
    if(c1.real>=c2.real && c1.img>=c2.img)
        return true;
    else
        return false;
}
int main()
{
    Complex c1,c2,c3;
    cout<<"Enter the real and imaginary part of 1st complex number: ";
    cin>>c1;
    cout<<"Enter the real and imaginary part of 2nd complex number: ";
    cin>>c2;
    c3=c1+c2;
    cout<<"Addition of "<<c1<<" and "<<c2<<" is "<<c3<<endl;
    c3=c1-c2;
    cout<<"Subtraction of "<<c1<<" and "<<c2<<" is "<<c3<<endl;
    c3=c1*c2;
    cout<<"Multiplication of "<<c1<<" and "<<c2<<" is "<<c3<<endl;
    c3=c1/c2;
    cout<<"Division of "<<c1<<" and "<<c2<<" is "<<c3<<endl;
    if(c1==c2)
        cout<<c1<<" and "<<c2<<" are equal"<<endl;
    else
        cout<<c1<<" and "<<c2<<" are not equal"<<endl;
    if(c1!=c2)
        cout<<c1<<" and "<<c2<<" are not equal"<<endl;
    else
        cout<<c1<<" and "<<c2<<" are equal"<<endl;
    if(c1<c2)
        cout<<c1<<" is less than "<<c2<<endl;
    else
        cout<<c1<<" is not less than "<<c2<<endl;
    if(c1>c2)
        cout<<c1<<" is greater than "<<c2<<endl;
    else
        cout<<c1<<" is not greater than "<<c2<<endl;
    if(c1<=c2)
        cout<<c1<<" is less than or equal to "<<c2<<endl;
    else
        cout<<c1<<" is not less than or equal to "<<c2<<endl;
    if(c1>=c2)
        cout<<c1<<" is greater than or equal to "<<c2<<endl;
    else
        cout<<c1<<" is not greater than or equal to "<<c2<<endl;
    return 0;
}
/*  
Enter the real and imaginary part of 1st complex number: 1+2i
Enter the real and imaginary part of 2nd complex number: 3+4i
Addition of 1+2i and 3+4i is 4+6i
Subtraction of 1+2i and 3+4i is -2+-2i
Multiplication of 1+2i and 3+4i is -5+10i
Division of 1+2i and 3+4i is -0.44+0.08i
1+2i and 3+4i are not equal
1+2i and 3+4i are equal
1+2i is not less than 3+4i
1+2i is greater than 3+4i
1+2i is not greater than or equal to 3+4i
1+2i is less than or equal to 3+4i
*/