// friend_call in c++
#include<bits/stdc++.h>
using namespace std;
class A
{
    private:
        int x =5;
    public:
        friend class B;
    protected:
        int y = 10;
};
class B
{
    public:
        void display(A &a)
        {
            cout<<"\nthe private data is : "<<a.x;
            cout<<"\nthe protected data is : "<<a.y;
        }
};
int main()
{
    A a;
    B b;
    b.display(a);
}