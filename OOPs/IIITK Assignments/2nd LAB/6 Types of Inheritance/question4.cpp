// To show hybrid inheritance
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
class B
{
    public:
    int b;
    B()
    {
        b=20;
    }
};
class C:public A,public B
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

// #include<bits/stdc++.h>
// using namespace std;
// class Shape
// {
// 	protected:
// 		int width, height;
// 	public:
// 		void setWidth(int w)
// 		{
// 			width = w;
// 		}
// 		void setHeight(int h)
// 		{
// 			height = h;
// 		}
// };
// class Rectangle: public Shape
// {
//     public:
//         int area()
//         {
//             return (width * height);
//         }
// };
// class Triangle: public Shape
// {
//     public:
//         int area()
//         {
//             return (width * height / 2);
//         }
// };
// int main()
// {
//     Rectangle r;
//     Triangle t;
//     r.setWidth(5);
//     r.setHeight(7);
//     t.setWidth(8);
//     t.setHeight(4);
//     cout << "Area of Rectangle: " << r.area() << endl;
//     cout << "Area of Triangle: " << t.area() << endl;
//     return 0;
// }
// Output:
// Area of Rectangle: 35
// Area of Triangle: 16
