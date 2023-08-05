// protected_modifier in c++
#include<bits/stdc++.h>
using namespace std;
class Protected
{
    protected:
        int id;
};
class Public: public Protected
{
    int x;
    public:
        Public(int x):x(x){}
        void setId()
        {
            id = x;
        }
        void display()
        {
            cout<<"\nProtected memebr can also be changed : "<<id;
        }
};
int main()
{
    Public ob(5);
    ob.setid();
    ob.display();
    return 0;
}