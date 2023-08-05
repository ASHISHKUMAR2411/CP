#include <iostream>
using namespace std;
int fun(int number)
{
    cout << number << endl;
    return number;
}
int main()
{
    int a = 5;
    a = fun((fun(a), fun(++a), fun(++a)));
    cout << a << endl;
}