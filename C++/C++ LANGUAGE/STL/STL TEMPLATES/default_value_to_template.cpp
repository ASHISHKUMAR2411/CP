#include<iostream>
using namespace std;
template<class T, class U = char>
class A
{
private:
    /* data */
public:
    T x;
    U y;
    A()
    {
        cout<<"Constructor called "<<endl;
    };
    ~A()
    {
        cout<<"Destructor  called "<<endl;
    };
};
int main()
{
    A<char> a;
    return 0;
}
