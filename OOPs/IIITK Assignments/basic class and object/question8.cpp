/*  C++ Program to find Area of Rectangle using constructor  */

#include <iostream>
using namespace std;

class CRectArea
{
private:
    int length;
    int breadth;

public:
    CRectArea(int, int);

    int areaofrect()
    {
        return (length * breadth);
    }
    int length1()
    {
        return length;
    }

    int breadth1()
    {
        return breadth;
    }
};

CRectArea::CRectArea(int x, int y)
{
    length = x;
    breadth = y;
}

int main()
{
    CRectArea rect(2, 2);
    cout << "The Length of Rectangle :: " << rect.length1() << "\n";
    cout << "\nThe Breadth of Rectangle :: " << rect.breadth1() << "\n";
    cout << "\nThe area of rectangle is :: " << rect.areaofrect() << endl;
    return 0;
}