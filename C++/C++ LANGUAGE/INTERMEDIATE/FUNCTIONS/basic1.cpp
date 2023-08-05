#include <iostream>
#include <string>
using namespace std;
template <typename T>
// we can use max as it is bydefault in c++ so we use Max ..
T Max(T x, T y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main()
{
    // In this we are going to discuss about the basics of function in c++
    int x = 5, y = 6;
    cin >> x >> y;
    cout << max(x, y) << endl;
    cout << Max<int>(x, y);
    return 0;
}