// private_modifier2 in c++
#include <bits/stdc++.h>
using namespace std;
class Private
{
    double radius;

public:
    void calArea(double r)
    {
        radius = r;
        cout << "\narea is : " << 3.14 * radius * radius;
    }
};
int main()
{
    Private p;
    p.calArea(7.7);
    return 0;
}