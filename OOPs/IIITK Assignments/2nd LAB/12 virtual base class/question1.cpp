// Write a C++ Program to shown the concept of Virtual Base Class also define a specific problem where we can use this concept for solving the specified problem using the Virtual Base Class concept.
#include<bits/stdc++.h>
using namespace std;
class Shape
{
    public:
        virtual void area()=0;
};
class Rectangle:public Shape
{
    public:
        void area()
        {
            cout<<"Area of Rectangle is : ";
        }
};
class Triangle:public Shape
{
    public:
        void area()
        {
            cout<<"Area of Triangle is : ";
        }
};
class Circle:public Shape
{
    public:
        void area()
        {
            cout<<"Area of Circle is : ";
        }
};
int main()
{
    Shape *s;
    Rectangle r;
    Triangle t;
    Circle c;
    s=&r;
    s->area();
    s=&t;
    s->area();
    s=&c;
    s->area();
    return 0;
}
// Output:
// Area of Rectangle is : 24
// Area of Triangle is : 12
// Area of Circle is : 28
//