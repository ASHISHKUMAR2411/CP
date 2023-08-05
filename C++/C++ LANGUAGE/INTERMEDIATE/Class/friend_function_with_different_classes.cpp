// friend_function_with_different_classes
#include <bits/stdc++.h>
using namespace std;
class B;
class A
{
private:
    int x;

public:
    void setdata(int i)
    {
        x = i;
    }
    friend void min(A a, B b);
};
class B
{
private:
    int y;

public:
    void setdata(int j)
    {
        y = j;
    }
    friend void min(A a, B b);
};
void min(A a, B b)
{
    if (a.x > b.y)
    {
        cout << b.y << "\n";
    }
    else
    {
        cout << a.x << "\n";
    }
}
int main()
{
    A a;
    B b;
    a.setdata(10);
    b.setdata(20);
    min(a, b);
    return 0;
}