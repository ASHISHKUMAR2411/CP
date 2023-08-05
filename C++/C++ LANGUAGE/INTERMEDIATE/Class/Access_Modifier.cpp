// Access_Modifier in classes and its overview
#include <bits/stdc++.h>
using namespace std;
#define pi 3.14
class learn
{
    // by default it is private if we do not specify the access modifier then
private:
    int priMem;

public:
    double radius;
    double area()
    {
        return pi * radius * radius;
    }

protected:
    double circumference()
    {
        return pi * 2 * radius;
    }
}; 
int main()
{
    learn object;
    object.radius = 5.6;
    cout << "\n the area is : " << object.area();
    return 0;
}