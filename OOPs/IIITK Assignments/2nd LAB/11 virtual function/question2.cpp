// Write a C++ program to create an class ‘Shape’, which is the base class of classes ‘Polygon’ and ‘Circle’. “Polygon” class is the base class from which a class Rectangular is derived.Now, create a virtual functions compute Area and compute Perimeter which are declared in the class Shape.These functions are actually defined in the derived classes
// “Rectangle” and “Circle”.Define the classes “Shape”, “Polygon”, “Rectangle” and “Circle”.Write a global function “ComputeAllArea” as double computeAllArea(Shape *s[100], int numberofShapes).The above function computes the total area of all shapes object pointed to by s[0], s[1], ....s[numberOfShapes].
// Write a main function to test the above function.
#include<bits/stdc++.h>
using namespace std;
class Shape
{
    public:
    virtual double computeArea()=0;
    virtual double computePerimeter()=0;
};
class Circle:public Shape
{
    public:
    double radius;
    Circle(double r)
    {
        radius=r;
    }
    double computeArea()
    {
        return 3.14*radius*radius;
    }
    double computePerimeter()
    {
        return 2*3.14*radius;
    }
};
class Polygon:public Shape
{
    public:
    double length,breadth;
    // Polygon(double l,double b)
    // {
    //     length=l;
    //     breadth=b;
    // }
    double computeArea()
    {
        return length*breadth;
    }
    double computePerimeter()
    {
        return 2*(length+breadth);
    }
};
class Rectangle:public Polygon
{
    public:
    Rectangle(double l,double b)
    {
        length=l;
        breadth=b;
    }
};
double computeAllArea(Shape *s[100], int numberofShapes)
{
    double totalArea=0.0;
    for(int i=0;i<numberofShapes;i++)
    {
        totalArea+=s[i]->computeArea();
    }
    return totalArea;
}

int main()
{
    int numberofShapes;
    cout<<"Enter the number of shapes: ";
    cin>>numberofShapes;
    Shape *s[100];
    for(int i=0;i<numberofShapes;i++)
    {
        int choice;
        cout<<"Enter the shape: "<<endl;
        cout<<"1. Circle"<<endl;
        cout<<"2. Rectangle"<<endl;
        cin>>choice;
        if(choice==1)
        {
            double radius;
            cout<<"Enter the radius: ";
            cin>>radius;
            s[i]=new Circle(radius);
        }
        else if(choice==2)
        {
            double length,breadth;
            cout<<"Enter the length: ";
            cin>>length;
            cout<<"Enter the breadth: ";
            cin>>breadth;
            s[i]=new Rectangle(length,breadth);
        }
    }  
    cout<<"Total area of all shapes: "<<computeAllArea(s,numberofShapes);
    return 0;
}

