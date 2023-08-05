// private_modifier in c++
#include<bits/stdc++.h>
using namespace std;
class Private
{
    private:
        float radius;
    public:
        Private(float r):radius(r){}
        void calArea()
        {
            cout<<"\nthe area is : "<<3.14*radius*radius;
        }
};
int main()
{
    Private p(7.7);
    p.calArea();
    return 0;
}